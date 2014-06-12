/*
 * Cow.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: josh
 */



#include<iostream>
#include "Cow.h"

Cow::Cow(int s, int l, int ear) : steaks(s), legs(l), e(ear){
	ca = new calf(e);
	std::cout << "Ears " << ca->ears << std::endl;
}

Cow::Cow(Cow& c)
{

e = 5;
legs = c.legs;
steaks = c.steaks;
ca = new calf(5);
}

Cow::~Cow()
{
	std::cout << "Deleted Calf with " << ca->ears << " ears" <<std::endl;
	delete ca;
}

