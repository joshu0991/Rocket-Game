/*
 * Cow.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: josh
 */




#include "Cow.h"

Cow::Cow(int s, int l, int ear) : steaks(s), legs(l), e(ear){};

Cow::Cow(Cow& c)
{
c.e = 12;
c.legs = legs;
c.steaks = steaks;
c.ca = new calf(c.e);

}
