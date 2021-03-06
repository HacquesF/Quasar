#include "PrmWindow.hpp"
#include <iostream>
PrmWindow::PrmWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject),
	  refBuilder(builder)
{

	//------------------la fenetre principale
	//builder->get_widget("main_window",mainWindow);
	refBuilder->get_widget("but_launchH",but_launchH);
	but_launchH->signal_clicked().connect( sigc::mem_fun(*this,&PrmWindow::on_launchH));
	
	refBuilder->get_widget("but_launchB",but_launchB);
	but_launchB->signal_clicked().connect( sigc::mem_fun(*this,&PrmWindow::on_launchB));
	
	refBuilder->get_widget("nbArgent", nbArgent);
	
	show_all_children();
	
	//--------------------Liaison fenetres
	refBuilder->get_widget_derived("HUM_Game",humWindow);
	humWindow->moreInit(&q);
	
	refBuilder->get_widget_derived("BOT_Game",botWindow);
	botWindow->moreInit(&q);
}

PrmWindow::~PrmWindow(){
}
void PrmWindow::moreInit(Glib::RefPtr<Gtk::Application>& app){
	refapp = app;
}
//--------Signal
void PrmWindow::on_launchH(){
	//Cache la fenetre principale
	//lance l autre avec l'argent
	//relance la princ
	humWindow->prepare(nbArgent->get_value_as_int());
	humWindow->show();
}

void PrmWindow::on_launchB(){
	botWindow->prepare(nbArgent->get_value_as_int());
	botWindow->show();
}
