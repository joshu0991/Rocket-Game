/*
 * Bin_Tree.h
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */

#ifndef BIN_TREE_H_
#define BIN_TREE_H_
#include "Bin_Node.h"
#include <iostream>
#include<cstdlib>
#include<string>
#include "Linked_List.h"
class Bin_Tree
{
public:
	Bin_Tree();
	void build_tree(Linked_List_Func* l);
private:
	bin_node* b_root;
	int decide_num(node* l);
	void find_root(bin_node**, int);

};

#endif /* BIN_TREE_H_ */
