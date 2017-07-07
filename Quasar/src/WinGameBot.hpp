#ifndef WINGAMEBOT_HPP
#define WINGAMEBOT_HPP
#include<gtkmm.h>
#include "Jeu.hpp"
#include "Robot.hpp"
#include "StrategyB1.hpp"
#include "StrategyB2.hpp"

class WinGameBot : public Gtk::Window {
	private :
		std::unique_ptr<Jeu> jeuQ;
		Robot bot;
		StrategyB1 strat1;
		StrategyB2 strat2;
		int argentBase;
	protected : 
		Gtk::Button* but_start, *but_stop;
		Gtk::Label* lblText;
		Gtk::ComboBoxText *cbt_strat;
		Gtk::SpinButton* nbGame;
		void on_clickStart();
		void on_clickStop();
		void on_changeStrat();
	public:
		WinGameBot(BaseObjectType* , const Glib::RefPtr<Gtk::Builder>& );
		virtual ~WinGameBot();
		
		void moreInit(Jeu*);
		void prepare(int s);

};
#endif
