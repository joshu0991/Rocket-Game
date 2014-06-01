/*
 * B_Tree_Imp.cpp
 *
 *  Created on: May 28, 2014
 *      Author: josh
 */

#include "Bin_Tree.h"
#include "Linked_List.h"
#include "Bin_Node.h"
#include <algorithm>

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
	int size = l->calc_size();
	bin_node** array = new bin_node*[size];
	int counter = 0;
	while(current != 0)
	{
		node = new bin_node();
		node->position = decide_num(current);
		node->contact = current->contact;
		node->phone = current->phone;
		current = current->next;
		array[counter] = node; //store the address of the node in an array <- find a better way to do this
		counter++;
	}
	find_root(array, size);
	delete array;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::find_root(bin_node** array, int size)
{
	int rootNum = NULL;
	int spotInArray;
	int num_array[size];
	for(int i = 0; i < size; i++)
	{

		bin_node* node = array[i];
		//sort the array
		int node_num = node->position;
		std::cout << "Node num " << node_num << std::endl;
	}
}
