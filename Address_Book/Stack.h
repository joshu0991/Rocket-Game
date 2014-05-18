/*
 * Stack.h
 *
 *  Created on: May 18, 2014
 *      Author: josh
 */
//Linked stack just for the fun of it! This has no application in the address book.
#ifndef STACK_H_
#define STACK_H_

#include "node.h"
class Stack
{
public:
	void push(std::string, std::string); //add node to stack with string contact and phone number
	node pop();//remove last node (LIFO) and return the node so the data get be obtained
};




#endif /* STACK_H_ */
