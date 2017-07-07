#include "WinGameHum.hpp"

//-----------------------------Constr
WinGameHum::WinGameHum(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& builder)
	: Gtk::Window(cobject),
	  joueur(0)
{
	
	//----------Boutons
	builder->get_widget("button1",but_1);
	but_1->signal_clicked().connect( sigc::mem_fun(*this,&WinGameHum::on_click1));
	
	builder->get_widget("button2",but_2);
	but_2->signal_clicked().connect( sigc::mem_fun(*this,&WinGameHum::on_click2));
	
	builder->get_widget("but_getGains",but_getGains);
	but_getGains->signal_clicked().connect( sigc::mem_fun(*this,&WinGameHum::on_clickGains));
	
	builder->get_widget("but_stopH",but_stop);
	but_stop->signal_clicked().connect( sigc::mem_fun(*this,&WinGameHum::on_clickStop));
	
	//-----------Label
	builder->get_widget("lbl_ScoreCour",lblScore);
	builder->get_widget("lbl_argentCour",lblArgent);
	
	show_all_children();
}

WinGameHum::~WinGameHum(){
}

//------------------------------Public
void WinGameHum::moreInit(Jeu* q){
	//Liaison du jeu
	jeuQ = std::unique_ptr<Jeu>(q);
}
void WinGameHum::prepare(int s){
	joueur.getCB()->setSolde(s);
	jeuQ.get()->recommencer(joueur.getCB());
	updateLabel();
}

//----------------------------Protected
//----------Button
void WinGameHum::on_click1(){
	jeuQ.get()->bouton1();
	updateLabel();
	jeuQ.get()->voirScore();
}
void WinGameHum::on_click2(){
	jeuQ.get()->bouton2();
	updateLabel();
	jeuQ.get()->voirScore();
}
void WinGameHum::on_clickGains(){
	jeuQ.get()->retirerGain(joueur.getCB());
	jeuQ.get()->recommencer(joueur.getCB());
	updateLabel();
}
void WinGameHum::on_clickStop(){
	jeuQ.get()->retirerGain(joueur.getCB());
	hide();
}

//-------------------------------Private
void WinGameHum::updateLabel(){
	char buffer [30];
	int s = jeuQ.get()->getScore();
	sprintf(buffer,"Score : %d",s);
	lblScore->set_text(buffer);
	sprintf(buffer,"Argent : %d",joueur.getCB()->getSolde());
	lblArgent->set_text(buffer);
}
