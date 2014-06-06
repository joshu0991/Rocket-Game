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
	~Bin_Tree();
	void build_tree(Linked_List_Func* l);
	void add_node(Linked_List_Func* l);
	void in_order(bin_node*);
	void post_order(bin_node*);
	void pre_order(bin_node*);
	void insert(int, bin_node*, bin_node*);
	bin_node* search(std::string);
private:
	bin_node* b_root;
	int decide_num(node* l);
	void find_root(bin_node**, int); //not sure if this will get used
	void Link_Nodes(bin_node** array, int);
	void balance_tree(bin_node*);
	void delete_in_order(bin_node*);
	int decide_bin_node_num(bin_node*);
	int decide_string_num(std::string);
};

#endif /* BIN_TREE_H_ */
