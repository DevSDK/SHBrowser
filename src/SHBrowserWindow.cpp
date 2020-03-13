#include "SHBrowserWindow.h"

SHBrowserWindow::SHBrowserWindow(WebKitWebView* webview)
{
	Gtk::Widget * wv = Glib::wrap(GTK_WIDGET(webview));
	
//	this->add(m_grid);
	this->add(*wv);
	this->set_title("SHBrowser");
	m_webview = webview;
	this->set_default_size( 800, 600 );
}

bool SHBrowserWindow::on_key_press_event(GdkEventKey* key_event)
{
	std::cout<<"?"<<std::endl;
	if((key_event->state & GDK_CONTROL_MASK) &&(key_event->state & GDK_SHIFT_MASK) && (key_event->keyval == 'I'))
	{	
		WebKitWebInspector*inspector = webkit_web_view_get_inspector(m_webview);
		if(!m_is_visible_inspector)
		{
			webkit_web_inspector_show(inspector);

			std::cout<<"INSPECT MODE ENABLED"<<std::endl;
			m_is_visible_inspector = true;
		}
		else
		{
			webkit_web_inspector_close(inspector);

			std::cout<<"INSPECT MODE DISABLED"<<std::endl;
			m_is_visible_inspector = false;
		}
	}

	switch(key_event->keyval)
	{
		case GDK_KEY_F5:
			reload_page(m_webview);	
		break;	

	}

	return true;
}

void SHBrowserWindow::reload_page(WebKitWebView* view)
{
	webkit_web_view_reload(view);
}

