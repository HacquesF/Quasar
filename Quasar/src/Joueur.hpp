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
#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Quasar.hpp"
#include "CarteBancaire.hpp"
enum ChoixPossible{
	AUCUN = 0,
	BOUTON1 = 1,
	BOUTON2 = 2,
	QUITTER = 3,
	GAIN = 4,
	REJOUER = 5
};
class Joueur{
	protected:
		CarteBancaire cb_;
	public:
		Joueur(int);
		virtual ChoixPossible getChoix(int)=0;
		CarteBancaire* getCB();
		void recoit(int);
		void donner(int);
		int argent();
};


#endif
