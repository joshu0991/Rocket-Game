/*
 * Bin_Node.h
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */

#ifndef BIN_NODE_H_
#define BIN_NODE_H_
#include<string>
#include "Linked_List.h"
struct bin_node : public Linked_List_Func
{
	bin_node* left;
	bin_node* right;
	std::string contact;
	std::string phone;
};

#endif /* BIN_NODE_H_ */
