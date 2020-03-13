#include <iostream>
#include <gtkmm.h>
#include <gtk/gtk.h>
#include "webkit2/webkit2.h"
#include "SHBrowserWindow.h"
// TESTING AREA




//




int main (int argc, char** argv)
{
	
	gtk_init(&argc, &argv);
	
	WebKitSettings *webkitSettings = webkit_settings_new();
	webkit_settings_set_enable_developer_extras(webkitSettings, TRUE);
	webkit_settings_set_enable_webgl(webkitSettings, TRUE);
	webkit_settings_set_enable_media_stream(webkitSettings, TRUE);
	webkit_settings_set_enable_media_capabilities(webkitSettings, TRUE);
	webkit_settings_set_enable_html5_database(webkitSettings, TRUE);
	webkit_settings_set_enable_html5_local_storage(webkitSettings, TRUE);
	webkit_settings_set_enable_page_cache(webkitSettings, TRUE);
	webkit_settings_set_javascript_can_open_windows_automatically(webkitSettings, TRUE);
	webkit_settings_set_enable_developer_extras(webkitSettings, TRUE);
	WebKitWebContext* context = webkit_web_context_get_default();
    webkit_web_context_set_favicon_database_directory(context, NULL);
	

	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create( argc, argv, "" );



	WebKitWebView * one =  WEBKIT_WEB_VIEW(webkit_web_view_new_with_context(context));
	
	SHBrowserWindow window(one);
 
	webkit_web_view_set_settings(one, webkitSettings);
  webkit_web_view_load_uri(one, "http://google.com/");

  window.show_all();

  app->run( window );  
  exit( 0 );
	return 0;
}
