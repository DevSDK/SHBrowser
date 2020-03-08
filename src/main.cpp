#include <iostream>
#include <gtkmm.h>
#include <gtk/gtk.h>
#include "webkit2/webkit2.h"

// TESTING AREA

//




int main (int argc, char** argv)
{
	
	gtk_init(&argc, &argv);
	
	WebKitSettings *webkitSettings = webkit_settings_new();
	webkit_settings_set_enable_developer_extras(webkitSettings, TRUE);
	webkit_settings_set_enable_webgl(webkitSettings, TRUE);
	webkit_settings_set_enable_media_stream(webkitSettings, TRUE);
	WebKitWebContext* context = webkit_web_context_get_default();
    webkit_web_context_set_favicon_database_directory(context, NULL);
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create( argc, argv, "" );

  Gtk::Window window;
  window.set_default_size( 800, 600 );

  WebKitWebView * one =  WEBKIT_WEB_VIEW( webkit_web_view_new() );
  /*
   * the next line does some tricks :
   * GTK_WIDGET( one ) -> convert WebKitWebView to GtkWidget (one->two)
   * Glib::wrap( GTK_WIDGET( one ) ) -> convert GtkWidget to Gtk::Widget (two->three)
   */
  Gtk::Widget * three = Glib::wrap( GTK_WIDGET( one ) );

  window.add( *three );
  webkit_web_view_load_uri(one, "http://google.com/");

  window.show_all();

  app->run( window );  
  exit( 0 );
	return 0;
}
