/*
 * B_Tree_Imp.cpp
 *
 *  Created on: May 28, 2014
 *      Author: josh
 */



#include "Bin_Tree.h"
#include "Linked_List.h"
#include "Bin_Node.h"

//decide where the contact should go on the btree based on abc order and assign a number
Bin_Tree::Bin_Tree() : b_root(0){}

int Bin_Tree::decide_num(node* l)
{
		std::string c = l->contact;
		int r_var = 0;
		for (unsigned int i = 0; i < c.length(); i++)
		{
			r_var += (c.at(i)-'0'); // char 0 is 41 converting to integers
		}
		return r_var;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::build_tree(Linked_List_Func* l)
{
	//std::cout << "Entered Bt" << std::endl;
	node* current = l->root;
	bin_node* node;
	while(current != 0)
	{
		node = new bin_node();
		std::string a = current->contact;
		std::cout << a << std::endl;
		node->position = decide_num(current);
		node->contact = current->contact;
		node->phone = current->phone;
		std::cout << node->position << std::endl;
		current = current->next;
		//find the root
		//link nodes in some order


	}
}
