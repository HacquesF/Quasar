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
#ifndef ChoixBouton_HPP
#define ChoixBouton_HPP
#include <memory>
#include <random>
#include "Score.hpp"
class ChoixBouton:public Score{
	protected:
		Score* decore_;
		int getRandom(int, int);
	public:
		ChoixBouton(Score*);
		~ChoixBouton();
		virtual int getScore()=0;
};
#endif
