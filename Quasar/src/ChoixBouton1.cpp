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
#include "ChoixBouton1.hpp"
ChoixBouton1::ChoixBouton1(Score* d):ChoixBouton(d){
	this->score_ = getRandom(4,7);
}
int ChoixBouton1::getScore(){
	return this->score_ + decore_->getScore();
}
