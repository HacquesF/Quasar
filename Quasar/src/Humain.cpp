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

Humain::Humain(int a) : Joueur(a){}
ChoixPossible Humain::getChoix(int score){
	ChoixPossible res = AUCUN;
	std::string choix;
	std::cout<<"q pour Quitter, 1 pour bouton 1, 2 pour bouton 2, g pour amasser les gains, r pour rejouer\n";
	std::cin>>choix;
	if(choix == "q"){
		res = QUITTER;
	}else if(choix == "1"){
		res= BOUTON1;
	}else if(choix == "2"){
		res=BOUTON2;
	}else if(choix == "g"){
		res = GAIN;
	}else if(choix == "r"){
		res = REJOUER;
	}else{
		std::cout<<"Votre entree : "<<choix<<" ne fait pas parti des choix\n";
	}
	return res;
}
