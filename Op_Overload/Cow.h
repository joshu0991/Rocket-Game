/*
 * Cow.h
 *
 *  Created on: Jun 11, 2014
 *      Author: josh
 */

#ifndef COW_H_
#define COW_H_

class calf{
	int ears;
public:
	calf(int e) : ears(e){};

};

class Cow
{

	int steaks;
	int legs;
	int e;
	calf* ca = new calf(e);
public:
	Cow(int, int, int);
	Cow(Cow& c);
};


#endif /* COW_H_ */
