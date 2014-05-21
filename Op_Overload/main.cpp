/*
 * main.cpp
 *
 *  Created on: May 20, 2014
 *      Author: josh
 */

#include "Overload_Op.h"
#include <iostream>
#include<sstream>
int main()
{
	std::stringstream s;
	std::string st;
	Over_Load O1(12);
	Over_Load O2(24);
	Over_Load O3;
	O3 = O1+O2;
	s << O3.data;
	st = s.str();
	std::cout << "Data " + st << std::endl;
}
