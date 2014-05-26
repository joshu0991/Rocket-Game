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
	std::string url;
	bool used; //field I am adding so I can use this to randomly choose my daily schedule while I am on vacation :)
	node *next;
};



#endif /* NODE_H_ */
