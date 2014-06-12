/*
 * Cow.h
 *
 *  Created on: Jun 11, 2014
 *      Author: josh
 */

#ifndef COW_H_
#define COW_H_

class calf{

public:
	int ears;
	calf(int e) : ears(e){};

};

class Cow
{

	int steaks;
	int e;
public:
	int legs;
	calf* ca;
	Cow(int, int, int);
	Cow(Cow& c);
	~Cow();
};


#endif /* COW_H_ */
