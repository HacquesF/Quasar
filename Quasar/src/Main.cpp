/**
Copyright 2016 Florian HACQUES 501B
This file is part of Quasar.

    Quasar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Quasar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Quasar.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "Humain.hpp"
#include "Robot.hpp"
#include "Quasar.hpp"
#include "PrmWindow.hpp"
#include <gtkmm.h>

void click_startH(){
	std::cout<<"Bijouor\n";
}
int main(int argc, char* argv[]){
	//-------------------GTK thingy
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	auto builder = Gtk::Builder::create();
	try
  {
    builder->add_from_file("Quasar/glade/window_main.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }
	
	PrmWindow* mainWindow= nullptr;
	builder->get_widget_derived("main_window",mainWindow);
	mainWindow->moreInit(app);
  return app->run(*mainWindow);
	
	
//	//----------------------Quasar
//	Quasar q;
//	std::unique_ptr<Jeu> jeuQ = std::unique_ptr<Jeu>(&q);	
//	if(argc == 1){
//		Humain j (50);
//		jeuQ.get()->recommencer(j.getCB());
//		ChoixPossible chx = AUCUN;
//		while(chx != QUITTER){
//			jeuQ.get()->voirScore();
//			chx =j.getChoix(jeuQ.get()->getScore());
//			switch(chx){
//				case BOUTON1:
//					jeuQ.get()->bouton1();
//					break;
//				case BOUTON2:
//					jeuQ.get()->bouton2();
//					break;
//				case GAIN:
//					jeuQ.get()->retirerGain(j.getCB());
//					break;
//				case REJOUER:
//					jeuQ.get()->recommencer(j.getCB());
//					break;
//				default:;
//			}
//		}
//		std::cout<<"Vous avez terminé avec : "<<j.getCB()->getSolde()<<std::endl;
//	}else{//bot en argument lance un nombre de partie de robot voulue
//		int nbGame = std::stoi(argv[1]);
//		Robot r(0);
//		r.seeStrat();
//		ChoixPossible chx = AUCUN;
//		for(int i=0;i<nbGame;++i){//Compteur de partie
//			jeuQ.get()->recommencer(r.getCB());
//			while(jeuQ->getEtat()){//tant que la partie est en cours
//				chx =r.getChoix(jeuQ.get()->getScore());
//				switch(chx){
//					case BOUTON1:
//						jeuQ.get()->bouton1();
//						break;
//					case BOUTON2:
//						jeuQ.get()->bouton2();
//						break;
//					case GAIN:
//						jeuQ.get()->retirerGain(r.getCB());
//						break;
//					case AUCUN:
//						std::cout<<"Choix Inconnu\n";
//						break;
//					default:;
//				}
//			}
//			std::cout<<jeuQ.get()->getScore()<<":"<<r.getCB()->getSolde()<<" | ";
//		}
//		std::cout<<"\nAvec "<<nbGame<<" partie, le robot a eu : "<<r.getCB()->getSolde()<<std::endl;
//	}
	//return 0;
}

//----------------GTK function

