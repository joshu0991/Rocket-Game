/*
 * Linked_List.h
 *
 *  Created on: May 17, 2014
 *      Author: josh
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "node.h"
class Linked_List_Func
{
public:
	void add_node_end(std::string, std::string, node*);
	node* add_first(std::string, std::string);
	void traverse_List(node*);
};



#endif /* LINKED_LIST_H_ */
