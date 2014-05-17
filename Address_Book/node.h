/*
 * node.h
 *
 *  Created on: May 17, 2014
 *      Author: josh
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include<string>
struct node
{
	std::string contact;
	std::string phone;
	bool used;
	node *next;
};



#endif /* NODE_H_ */
