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
#include "CarteBancaire.hpp"
#include <iostream>
CarteBancaire::CarteBancaire(int a) : solde_(a){}

void CarteBancaire::depot(int a){
	solde_+= a;
}
void CarteBancaire::retrait(int a){
	solde_= solde_ - a;
}
int CarteBancaire::getSolde(){
	return solde_;
}
void CarteBancaire::setSolde(int s){
	solde_ = s;
}
