/*
 * Overload_Op.h
 *
 *  Created on: May 20, 2014
 *      Author: josh
 */

#ifndef OVERLOAD_OP_H_
#define OVERLOAD_OP_H_
#include <iostream>
class Over_Load
{
public:
	Over_Load();
	Over_Load(int a);
	Over_Load operator+ (const Over_Load & a);

	int data;
};



#endif /* OVERLOAD_OP_H_ */
