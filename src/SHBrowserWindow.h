#ifndef __SHBROWSER_WINDOW_H__
#define __SHBROWSER_WINDOW_H_
#include <iostream>
#include <gtkmm.h>
#include <gtk/gtk.h>
#include "webkit2/webkit2.h"

class SHBrowserWindow : public Gtk::Window
{

	public:
		SHBrowserWindow(WebKitWebView*);

	private:
		bool on_key_press_event(GdkEventKey*) override; 
		
		void reload_page(WebKitWebView*);


		Gtk::Grid m_grid;	
		WebKitWebView* m_webview;
		bool m_is_visible_inspector = false;
};

#endif
