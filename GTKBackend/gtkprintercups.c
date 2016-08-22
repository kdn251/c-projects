/* GtkPrinterCupsCups
 * Copyright (C) 2006 John (J5) Palmieri  <johnp@redhat.com>
 * Copyright (C) 2011 Richard Hughes <rhughes@redhat.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <glib/gi18n-lib.h>

#ifdef HAVE_COLORD
#include <colord.h>
#endif

#include "gtkintl.h"
#include "gtkprintercups.h"

enum {
  PROP_0,
  PROP_PROFILE_TITLE
};

static void gtk_printer_cups_init       (GtkPrinterCups      *printer);
static void gtk_printer_cups_class_init (GtkPrinterCupsClass *class);
static void gtk_printer_cups_finalize   (GObject             *object);

static GtkPrinterClass *gtk_printer_cups_parent_class;
static GType gtk_printer_cups_type = 0;

static void gtk_printer_cups_set_property (GObject      *object,
                                           guint         prop_id,
                                           const GValue *value,
                                           GParamSpec   *pspec);
static void gtk_printer_cups_get_property (GObject      *object,
                                           guint         prop_id,
                                           GValue       *value,
                                           GParamSpec   *pspec);

void 
gtk_printer_cups_register_type (GTypeModule *module)
{
  const GTypeInfo object_info =
  {
    sizeof (GtkPrinterCupsClass),
    (GBaseInitFunc) NULL,
    (GBaseFinalizeFunc) NULL,
    (GClassInitFunc) gtk_printer_cups_class_init,
    NULL,           /* class_finalize */
    NULL,           /* class_data */
    sizeof (GtkPrinterCups),
    0,              /* n_preallocs */
    (GInstanceInitFunc) gtk_printer_cups_init,
  };

 gtk_printer_cups_type = g_type_module_register_type (module,
                                                      GTK_TYPE_PRINTER,
                                                      "GtkPrinterCups",
                                                      &object_info, 0);
}

GType
gtk_printer_cups_get_type (void)
{
  return gtk_printer_cups_type;
}

static void
gtk_printer_cups_class_init (GtkPrinterCupsClass *class)
{
  GObjectClass *object_class = (GObjectClass *) class;

  object_class->finalize = gtk_printer_cups_finalize;
  object_class->set_property = gtk_printer_cups_set_property;
  object_class->get_property = gtk_printer_cups_get_property;

  gtk_printer_cups_parent_class = g_type_class_peek_parent (class);

  g_object_class_install_property (G_OBJECT_CLASS (class),
                                   PROP_PROFILE_TITLE,
                                   g_param_spec_string ("profile-title",
                                                        P_("Color Profile Title"),
                                                        P_("The title of the color profile to use"),
                                                        "",
                                                        G_PARAM_READABLE));
}

static void
gtk_printer_cups_init (GtkPrinterCups *printer)
{
  printer->device_uri = NULL;
  printer->printer_uri = NULL;
  printer->state = 0;
  printer->hostname = NULL;
  printer->port = 0;
  printer->ppd_name = NULL;
  printer->ppd_file = NULL;
  printer->default_cover_before = NULL;
  printer->default_cover_after = NULL;
  printer->remote = FALSE;
  printer->get_remote_ppd_poll = 0;
  printer->get_remote_ppd_attempts = 0;
  printer->remote_cups_connection_test = NULL;
  printer->auth_info_required = NULL;
  printer->default_number_up = 1;
#ifdef HAVE_CUPS_API_1_6
  printer->avahi_browsed = FALSE;
  printer->avahi_name = NULL;
  printer->avahi_type = NULL;
  printer->avahi_domain = NULL;
#endif
  printer->ipp_version_major = 1;
  printer->ipp_version_minor = 1;
  printer->supports_copies = FALSE;
  printer->supports_collate = FALSE;
  printer->supports_number_up = FALSE;
  printer->media_default = NULL;
  printer->media_supported = NULL;
  printer->media_size_supported = NULL;
  printer->media_bottom_margin_default = 0;
  printer->media_top_margin_default = 0;
  printer->media_left_margin_default = 0;
  printer->media_right_margin_default = 0;
  printer->media_margin_default_set = FALSE;
  printer->sides_default = NULL;
  printer->sides_supported = NULL;
  printer->number_of_covers = 0;
  printer->covers = NULL;
  printer->output_bin_default = NULL;
  printer->output_bin_supported = NULL;
  
  /* Kevin's Code (Start) */
  
  printer->document_format_default = NULL;
  printer->document_format_supported = NULL;
  
  printer->color_supported_default = NULL;
  printer->color_supported = NULL;
  
  printer->media_source_default = NULL;
  printer->media_source_supported = NULL;
  
  printer->print_quality_default = 4;
  printer->print_quality_supported = NULL;
  
  printer->printer_resolution_default = NULL;
  printer->printer_resolution_supported = NULL;
  
  printer->copies_default = NULL;
  printer->copies_supported = NULL;
  
  printer->media_type_default = NULL;
  printer->media_type_supported = NULL;
  
  printer->pages_per_side_default = NULL;
  printer->pages_per_side_supported = NULL;
  
  printer->finishings_default = 3;
  printer->finishings_supported = NULL;
  
  printer->presentation_direction_number_up_default = NULL;
  printer->presentation_direction_number_up_supported = NULL;
  
  printer->page_delivery_default = NULL;
  printer->page_delivery_supported = NULL;
  
  printer->page_order_received_default = NULL;
  printer->page_order_received_supported = NULL;
  
  printer->print_color_mode_default = NULL;
  printer->print_color_mode_supported = NULL;
  
  printer->print_content_optimize_default = NULL;
  printer->print_content_optimize_supported = NULL;
  
  printer->print_scaling_default = NULL;
  printer->print_scaling_supported = NULL;
  
  printer->imposition_template_default = NULL;
  printer->imposition_template_supported = NULL;
  
  printer->job_account_type_default = NULL;
  printer->job_account_type_supported = NULL;
  
  printer->job_delay_output_until_default = NULL;
  printer->job_delay_output_until_supported = NULL;
  
  printer->job_error_action_default = NULL;
  printer->job_error_action_supported = NULL;
  
  printer->force_front_side_default = 67;
  printer->force_front_side_suppported = NULL;
  
  printer->print_rendering_intent_default = NULL;
  printer->print_rendering_intent_supported = NULL;
  
  printer->x_image_position_default = NULL;
  printer->x_image_position_supported = NULL;
  
  printer->y_image_position_default = NULL;
  printer->y_image_position_supported = NULL;
  
  /* Kevin's Code (End) */
  
}

static void
gtk_printer_cups_finalize (GObject *object)
{
  GtkPrinterCups *printer;

  g_return_if_fail (object != NULL);

  printer = GTK_PRINTER_CUPS (object);

  g_free (printer->device_uri);
  g_free (printer->printer_uri);
  g_free (printer->hostname);
  g_free (printer->ppd_name);
  g_free (printer->default_cover_before);
  g_free (printer->default_cover_after);
  g_strfreev (printer->auth_info_required);

#ifdef HAVE_COLORD
  if (printer->colord_cancellable)
    {
      g_cancellable_cancel (printer->colord_cancellable);
      g_object_unref (printer->colord_cancellable);
    }
  g_free (printer->colord_title);
  g_free (printer->colord_qualifier);
  if (printer->colord_client)
    g_object_unref (printer->colord_client);
  if (printer->colord_device)
    g_object_unref (printer->colord_device);
  if (printer->colord_profile)
    g_object_unref (printer->colord_profile);
#endif

#ifdef HAVE_CUPS_API_1_6
  g_free (printer->avahi_name);
  g_free (printer->avahi_type);
  g_free (printer->avahi_domain);
#endif

  g_strfreev (printer->covers);

  if (printer->ppd_file)
    ppdClose (printer->ppd_file);

  g_free (printer->media_default);
  g_list_free_full (printer->media_supported, g_free);
  g_list_free_full (printer->media_size_supported, g_free);

  g_free (printer->sides_default);
  g_list_free_full (printer->sides_supported, g_free);

  g_free (printer->output_bin_default);
  g_list_free_full (printer->output_bin_supported, g_free);
  
  /* Kevin's Code (Start) */
  
  g_free (printer->document_format_default);
  g_list_free_full (printer->document_format_supported, g_free);
  
  g_free (printer->color_supported_default);
  g_list_free_full (printer->color_supported, g_free);
  
  g_free (printer->media_source_default);
  g_list_free_full (printer->media_source_supported, g_free);
  
  g_list_free (printer->print_quality_supported);  
  
  g_free (printer->printer_resolution_default);
  g_list_free_full (printer->printer_resolution_supported, g_free);
  
  g_free (printer->copies_default);
  g_list_free_full (printer->copies_supported, g_free);
  
  g_free (printer->media_type_default);
  g_list_free_full (printer->media_type_supported, g_free);
  
  g_free (printer->pages_per_side_default);
  g_list_free_full (printer->pages_per_side_supported, g_free);
  
  /* Kevin's Code (Marek's patch start) */
  
  g_list_free (printer->finishings_supported);
    
  g_free (printer->page_delivery_default);
  g_list_free_full (printer->page_delivery_supported, g_free); 
  
  g_free (printer->page_order_received_default);
  g_list_free_full (printer->page_order_received_supported, g_free); 
  
  g_free (printer->presentation_direction_number_up_default);
  g_list_free_full (printer->presentation_direction_number_up_supported, g_free);   
  
  g_free (printer->print_color_mode_default);
  g_list_free_full (printer->print_color_mode_supported, g_free);         
  
  g_free (printer->print_content_optimize_default);
  g_list_free_full (printer->print_content_optimize_supported, g_free);           

  g_free (printer->print_scaling_default);
  g_list_free_full (printer->print_scaling_supported, g_free);    
  
  g_free (printer->imposition_template_default);
  g_list_free_full (printer->imposition_template_supported, g_free);
  
  g_free (printer->job_account_type_default);
  g_list_free_full (printer->job_account_type_supported, g_free);
  
  g_free (printer->job_delay_output_until_default);
  g_list_free_full (printer->job_delay_output_until_supported, g_free);
  
  g_free (printer->job_error_action_default);
  g_list_free_full (printer->job_error_action_supported, g_free);  	
  
  g_free (printer->print_rendering_intent_default);
  g_list_free_full (printer->print_rendering_intent_supported, g_free);  	  
  
  g_list_free (printer->print_rendering_intent_supported);
  
  g_free (printer->x_image_position_default);
  g_list_free_full (printer->x_image_position_supported, g_free);  
  	  
  g_free (printer->y_image_position_default);
  g_list_free_full (printer->y_image_position_supported, g_free);  	  
  
  /* Kevin's Code (Marek's patch end) */    
  
  /* Kevin's Code (End) */
  
  

  if (printer->get_remote_ppd_poll > 0)
    g_source_remove (printer->get_remote_ppd_poll);
  printer->get_remote_ppd_attempts = 0;

  gtk_cups_connection_test_free (printer->remote_cups_connection_test);

  G_OBJECT_CLASS (gtk_printer_cups_parent_class)->finalize (object);
}

static void
gtk_printer_cups_set_property (GObject         *object,
                               guint            prop_id,
                               const GValue    *value,
                               GParamSpec      *pspec)
{
  switch (prop_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

static void
gtk_printer_cups_get_property (GObject    *object,
                               guint       prop_id,
                               GValue     *value,
                               GParamSpec *pspec)
{
#ifdef HAVE_COLORD
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (object);
#endif

  switch (prop_id)
    {
    case PROP_PROFILE_TITLE:
#ifdef HAVE_COLORD
      if (printer->colord_title)
        g_value_set_string (value, printer->colord_title);
      else
        g_value_set_static_string (value, "");
#else
      g_value_set_static_string (value, NULL);
#endif
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
    }
}

#ifdef HAVE_COLORD

static void
colord_update_ui_from_settings (GtkPrinterCups *printer)
{
  const gchar *title = NULL;

  /* not yet connected to colord */
  if (printer->colord_client == NULL)
    goto out;
  if (!cd_client_get_connected (printer->colord_client))
    goto out;

  /* failed to get a colord device for the printer */
  if (printer->colord_device == NULL)
    {
      /* TRANSLATORS: when we're running an old CUPS, and
       * it hasn't registered the device with colord */
      title = _("Color management unavailable");
      goto out;
    }

  /* when colord prevents us from connecting (should not happen) */
  if (!cd_device_get_connected (printer->colord_device))
    goto out;

  /* failed to get a colord device for the printer */
  if (printer->colord_profile == NULL)
    {
      /* TRANSLATORS: when there is no color profile available */
      title = _("No profile available");
      goto out;
    }

  /* when colord prevents us from connecting (should not happen) */
  if (!cd_profile_get_connected (printer->colord_profile))
    goto out;
  title = cd_profile_get_title (printer->colord_profile);
  if (title == NULL)
    {
      /* TRANSLATORS: when the color profile has no title */
      title = _("Unspecified profile");
      goto out;
    }

out:
  /* SUCCESS! */
  if (g_strcmp0 (title, printer->colord_title) != 0)
    {
      g_free (printer->colord_title);
      printer->colord_title = g_strdup (title);
      g_object_notify (G_OBJECT (printer), "profile-title");
    }
  return;
}

static void
colord_client_profile_connect_cb (GObject *source_object,
                                  GAsyncResult *res,
                                  gpointer user_data)
{
  gboolean ret;
  GError *error = NULL;
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (user_data);

  ret = cd_profile_connect_finish (CD_PROFILE (source_object),
                                   res,
                                   &error);
  if (!ret)
    {
      g_warning ("failed to get properties from the profile: %s",
                 error->message);
      g_error_free (error);
    }

  /* update the UI */
  colord_update_ui_from_settings (printer);

  g_object_unref (printer);
}

static void
colord_client_device_get_profile_for_qualifiers_cb (GObject *source_object,
                                                    GAsyncResult *res,
                                                    gpointer user_data)
{
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (user_data);
  GError *error = NULL;

  printer->colord_profile = cd_device_get_profile_for_qualifiers_finish (printer->colord_device,
                                                                         res,
                                                                         &error);
  if (printer->colord_profile == NULL)
    {
      /* not having a profile for a qualifier is not a warning */
      g_debug ("no profile for device %s: %s",
               cd_device_get_id (printer->colord_device),
               error->message);
      g_error_free (error);
      goto out;
    }

  /* get details about the profile */
  cd_profile_connect (printer->colord_profile,
                      printer->colord_cancellable,
                      colord_client_profile_connect_cb,
                      g_object_ref (printer));
out:
  /* update the UI */
  colord_update_ui_from_settings (printer);

  g_object_unref (printer);
}

void
gtk_printer_cups_update_settings (GtkPrinterCups *printer,
                                  GtkPrintSettings *settings,
                                  GtkPrinterOptionSet *set)
{
  gchar *qualifier = NULL;
  gchar **qualifiers = NULL;
  GtkPrinterOption *option;
  const gchar *format[3];

  /* nothing set yet */
  if (printer->colord_device == NULL)
    goto out;
  if (!cd_device_get_connected (printer->colord_device))
    goto out;

  /* cupsICCQualifier1 */
  option = gtk_printer_option_set_lookup (set, "cups-ColorSpace");
  if (option == NULL)
    option = gtk_printer_option_set_lookup (set, "cups-ColorModel");
  if (option != NULL)
    format[0] = option->value;
  else
    format[0] = "*";

  /* cupsICCQualifier2 */
  option = gtk_printer_option_set_lookup (set, "cups-OutputMode");
  if (option != NULL)
    format[1] = option->value;
  else
    format[1] = "*";

  /* cupsICCQualifier3 */
  option = gtk_printer_option_set_lookup (set, "cups-Resolution");
  if (option != NULL)
    format[2] = option->value;
  else
    format[2] = "*";

  /* get profile for the device given the qualifier */
  qualifier = g_strdup_printf ("%s.%s.%s,%s.%s.*,%s.*.*",
                               format[0], format[1], format[2],
                               format[0], format[1],
                               format[0]);

  /* only requery colord if the option that was changed would give
   * us a different profile result */
  if (g_strcmp0 (qualifier, printer->colord_qualifier) == 0)
    goto out;

  qualifiers = g_strsplit (qualifier, ",", -1);
  cd_device_get_profile_for_qualifiers (printer->colord_device,
                                        (const gchar **) qualifiers,
                                        printer->colord_cancellable,
                                        colord_client_device_get_profile_for_qualifiers_cb,
                                        g_object_ref (printer));

  /* save for the future */
  g_free (printer->colord_qualifier);
  printer->colord_qualifier = g_strdup (qualifier);

  /* update the UI */
  colord_update_ui_from_settings (printer);
out:
  g_free (qualifier);
  g_strfreev (qualifiers);
}

static void
colord_client_device_connect_cb (GObject *source_object,
                                 GAsyncResult *res,
                                 gpointer user_data)
{
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (user_data);
  gboolean ret;
  GError *error = NULL;

  /* get details about the device */
  ret = cd_device_connect_finish (CD_DEVICE (source_object), res, &error);
  if (!ret)
    {
      g_warning ("failed to get properties from the colord device: %s",
                 error->message);
      g_error_free (error);
      goto out;
    }
out:
  /* update the UI */
  colord_update_ui_from_settings (printer);

  g_object_unref (printer);
}

static void
colord_client_find_device_cb (GObject *source_object,
                              GAsyncResult *res,
                              gpointer user_data)
{
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (user_data);
  GError *error = NULL;

  /* get the new device */
  printer->colord_device = cd_client_find_device_finish (printer->colord_client,
                                               res,
                                               &error);
  if (printer->colord_device == NULL)
    {
      g_warning ("failed to get find a colord device: %s",
                 error->message);
      g_error_free (error);
      goto out;
    }

  /* get details about the device */
  g_cancellable_reset (printer->colord_cancellable);
  cd_device_connect (printer->colord_device,
                     printer->colord_cancellable,
                     colord_client_device_connect_cb,
                     g_object_ref (printer));
out:
  /* update the UI */
  colord_update_ui_from_settings (printer);

  g_object_unref (printer);
}

static void
colord_update_device (GtkPrinterCups *printer)
{
  gchar *colord_device_id = NULL;

  /* not yet connected to the daemon */
  if (!cd_client_get_connected (printer->colord_client))
    goto out;

  /* not yet assigned a printer */
  if (printer->ppd_file == NULL)
    goto out;

  /* old cached profile no longer valid */
  if (printer->colord_profile)
    {
      g_object_unref (printer->colord_profile);
      printer->colord_profile = NULL;
    }

  /* old cached device no longer valid */
  if (printer->colord_device)
    {
      g_object_unref (printer->colord_device);
      printer->colord_device = NULL;
    }

  /* generate a known ID */
  colord_device_id = g_strdup_printf ("cups-%s", gtk_printer_get_name (GTK_PRINTER (printer)));

  g_cancellable_reset (printer->colord_cancellable);
  cd_client_find_device (printer->colord_client,
                         colord_device_id,
                         printer->colord_cancellable,
                         colord_client_find_device_cb,
                         g_object_ref (printer));
out:
  g_free (colord_device_id);

  /* update the UI */
  colord_update_ui_from_settings (printer);
}

static void
colord_client_connect_cb (GObject *source_object,
                          GAsyncResult *res,
                          gpointer user_data)
{
  gboolean ret;
  GError *error = NULL;
  GtkPrinterCups *printer = GTK_PRINTER_CUPS (user_data);

  ret = cd_client_connect_finish (CD_CLIENT (source_object),
                                  res, &error);
  if (!ret)
    {
      g_warning ("failed to contact colord: %s", error->message);
      g_error_free (error);
    }

  /* refresh the device */
  colord_update_device (printer);

  g_object_unref (printer);
}

static void
colord_printer_details_aquired_cb (GtkPrinterCups *printer,
                                   gboolean success,
                                   gpointer user_data)
{
  /* refresh the device */
  if (printer->colord_client)
    colord_update_device (printer);
}
#endif

/**
 * gtk_printer_cups_new:
 *
 * Creates a new #GtkPrinterCups.
 *
 * Returns: a new #GtkPrinterCups
 *
 * Since: 2.10
 **/
GtkPrinterCups *
gtk_printer_cups_new (const char      *name,
                      GtkPrintBackend *backend,
                      gpointer         colord_client)
{
  GObject *result;
  gboolean accepts_pdf;
  GtkPrinterCups *printer;

#if (CUPS_VERSION_MAJOR == 1 && CUPS_VERSION_MINOR >= 2) || CUPS_VERSION_MAJOR > 1
  accepts_pdf = TRUE;
#else
  accepts_pdf = FALSE;
#endif

  result = g_object_new (GTK_TYPE_PRINTER_CUPS,
			 "name", name,
			 "backend", backend,
			 "is-virtual", FALSE,
			 "accepts-pdf", accepts_pdf,
                         NULL);
  printer = GTK_PRINTER_CUPS (result);

#ifdef HAVE_COLORD
  /* connect to colord */
  if (colord_client != NULL)
    {
      printer->colord_cancellable = g_cancellable_new ();
      printer->colord_client = g_object_ref (CD_CLIENT (colord_client));
      cd_client_connect (printer->colord_client,
                         printer->colord_cancellable,
                         colord_client_connect_cb,
                         g_object_ref (printer));
    }

    /* update the device when we read the PPD */
    g_signal_connect (printer, "details-acquired",
                      G_CALLBACK (colord_printer_details_aquired_cb),
                      printer);
#endif

  /*
   * IPP version 1.1 has to be supported
   * by all implementations according to rfc 2911
   */
  printer->ipp_version_major = 1;
  printer->ipp_version_minor = 1;

  return printer;
}

ppd_file_t *
gtk_printer_cups_get_ppd (GtkPrinterCups *printer)
{
  return printer->ppd_file;
}

const gchar *
gtk_printer_cups_get_ppd_name (GtkPrinterCups  *printer)
{
  const gchar *result;

  result = printer->ppd_name;

  if (result == NULL)
    result = gtk_printer_get_name (GTK_PRINTER (printer));

  return result;
}
