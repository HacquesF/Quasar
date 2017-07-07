#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <gtkmm.h>
#include "Quasar.hpp"
#include "Humain.hpp"
#include "WinGameHum.hpp"
class PrmWindow : public Gtk::Window {
	private :
		Quasar q;
		WinGameHum* humWindow;
		Glib::RefPtr<Gtk::Application> refapp;
	protected : 
		//Gtk::Window* mainWindow;
		Glib::RefPtr<Gtk::Builder> refBuilder;
		Gtk::Button* but_launchH, *but_launchB;
		Gtk::SpinButton* nbArgent;
		
		void on_launchH();
		void on_launchB();
	public:
		PrmWindow(BaseObjectType* , const Glib::RefPtr<Gtk::Builder>& );
		virtual ~PrmWindow();
		void moreInit(Glib::RefPtr<Gtk::Application>&);
};

#endif
