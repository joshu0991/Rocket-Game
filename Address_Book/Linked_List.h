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
	void add_node_end(std::string, std::string, node*); //add first node
	node* add_first(std::string, std::string);//add nodes after first node
	void traverse_List(node*);//traverse and print entire list
};



#endif /* LINKED_LIST_H_ */
/*
 * to do
 * insert
 * delete
 * search
 * print list to file
 * read list from file
 * GUI Q(t)
 *
 */
