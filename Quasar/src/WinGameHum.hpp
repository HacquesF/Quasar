#ifndef WINGAMEHUM_HPP
#define WINGAMEHUM_HPP
#include<gtkmm.h>
#include "Jeu.hpp"
#include "Humain.hpp"
class WinGameHum : public Gtk::Window {
	private :
		std::unique_ptr<Jeu> jeuQ;
		Humain joueur;
		void updateLabel();
	protected : 
		Gtk::Button* but_1, *but_2, *but_getGains, *but_stop;
		Gtk::Label* lblScore, *lblArgent;
		void on_click1();
		void on_click2();
		void on_clickGains();
		void on_clickStop();
	public:
		WinGameHum(BaseObjectType* , const Glib::RefPtr<Gtk::Builder>& );
		virtual ~WinGameHum();
		
		void moreInit(Jeu*);
		void prepare(int s);

};
#endif
