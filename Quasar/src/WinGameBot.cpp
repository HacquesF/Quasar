#include "WinGameBot.hpp"

//-----------------------------Constr
WinGameBot::WinGameBot(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject),
	  bot(0)
{
	
	//----------Boutons
	builder->get_widget("but_start",but_start);
	but_start->signal_clicked().connect( sigc::mem_fun(*this,&WinGameBot::on_clickStart));
	
	builder->get_widget("but_stopB",but_stop);
	but_stop->signal_clicked().connect( sigc::mem_fun(*this,&WinGameBot::on_clickStop));
	
	//-----------Label
	builder->get_widget("lbl_bot", lblText);
	
	//-----------ComboText
	builder->get_widget("cbt_strat", cbt_strat);
	cbt_strat->signal_changed().connect( sigc::mem_fun(*this,&WinGameBot::on_changeStrat));
	
	//------------Spin
	builder->get_widget("nbGame",nbGame);
	
	show_all_children();
}

WinGameBot::~WinGameBot(){
}

//------------------------------Public
void WinGameBot::moreInit(Jeu* q){
	//Liaison du jeu
	jeuQ = std::unique_ptr<Jeu>(q);
}
void WinGameBot::prepare(int s){
	argentBase = s;
}

//----------------------------Protected
//----------Button
void WinGameBot::on_clickStart(){
	bot.getCB()->setSolde(argentBase);
	Glib::ustring buffer;
	char ligne [50];
	for(int i=0;i<nbGame->get_value_as_int();++i){//Compteur de partie
		jeuQ.get()->recommencer(bot.getCB());
		ChoixPossible chx = AUCUN;
		while(jeuQ->getEtat()){//tant que la partie est en cours
			chx =bot.getChoix(jeuQ.get()->getScore());
			switch(chx){
				case BOUTON1:
					jeuQ.get()->bouton1();
					break;
				case BOUTON2:
					jeuQ.get()->bouton2();
					break;
				case GAIN:
					jeuQ.get()->retirerGain(bot.getCB());
					break;
				case AUCUN:
					std::cout<<"Choix Inconnu\n";
					break;
				default:;
			}
		}
		sprintf(ligne,"Partie %d : finit avec %d \n",i,jeuQ.get()->getScore());
		buffer += ligne;
	}
	sprintf(ligne,"Il finit avec %d €\n",bot.getCB()->getSolde());
	buffer+=ligne;
	lblText->set_text(buffer);		
}
void WinGameBot::on_clickStop(){
	hide();
}

//--------------------------------Changement Spin
void WinGameBot::on_changeStrat(){
	Glib::ustring chx = cbt_strat->get_active_text();
	if(chx == "Strat1"){
		bot.changerStrat(&strat1);
	}else if(chx == "Strat2"){
		bot.changerStrat(&strat2);
	}else{
		std::cout<<chx<<"\n";
	}
}
