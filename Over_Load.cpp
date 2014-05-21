/*
 * Over_Load.cpp
 *
 *  Created on: May 20, 2014
 *      Author: josh
 */

#include "Overload_Op.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Over_Load Over_Load::operator +(const Over_Load& l)
{
	Over_Load ol;
	ol.data = this->data + l.data;
	return ol;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Over_Load::Over_Load(int a): data(a){ //initializer list
	std::cout << "Constructor Called" << std::endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Over_Load::Over_Load(){
	data = 0;
}
