/*
 * main.cpp
 *
 *  Created on: May 20, 2014
 *      Author: josh
 */

#include "Overload_Op.h"
#include <iostream>
#include<sstream>
#include "Cow.h"
using std::cout;
using std::endl;

int main()
{
	std::stringstream s;
	std::string st;

	Cow bess(100, 4, 3);
	Cow charlie(bess);
	int b = bess.ca->ears;
	int c = charlie.ca->ears;

	cout << "Bess's calves ears " << b <<" Charlie's calfs' ears " << c <<endl;

	//Over_Load O1(12);
	//Over_Load O2(24);
	//Over_Load O3;
	//O3 = O1+O2;
	//s << O3.data;
	//st = s.str();
	//std::cout << "Data " + st << std::endl;
}
