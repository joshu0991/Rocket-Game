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
		b_root = array[0];
		b_root->left = NULL;
		b_root->right = NULL;
		//link nodes and then balance or find root and then build balanced tree?
		counter++;
	}
	Link_Nodes(array, size);
	delete array;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::insert(int pos, bin_node* node, bin_node* leaf)
{
	if(pos < node->position)
	{
		if(leaf->left != NULL)
		{

		}
	}
	else if(pos > node->position)
	{
		if(leaf->right != NULL)
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::Link_Nodes(bin_node** array, int size)
{

	int counter = 1;
	while(counter < size)
	{
		bin_node* n = array[counter];
		bin_node* leaf = array[0];
		//handle case if this the root left and right have not been used yet.
		if(b_root->left == 0 && n->position < b_root->position)
		{
			b_root->left = n;
			counter++;
		}
		if(b_root->right == 0 && n->position > b_root->position)
		{
			b_root->right = n;
			counter++;
		}

		if(b_root->left == 0 && b_root->right == 0)
		{
			insert(n->position, n, leaf);
			counter++;
		}

	}


}
