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
	int size = l->calc_size();
	bin_node** array = new bin_node*[size];
	int counter = 0;
	while(current != 0)
	{
		node = new bin_node();
		node->position = decide_num(current);
		node->contact = current->contact;
		node->phone = current->phone;
		node->left = NULL;
		node->right = NULL;
		current = current->next;
		array[counter] = node;
		counter++;//store the address of the node in an array <- find a better way to do this
	}
	b_root = array[0];
	b_root->left = NULL;
	b_root->right = NULL;
	std::cout << " Root is " << b_root->contact << std::endl;
	Link_Nodes(array, size);
	//temporary test
	in_order(b_root);
	delete array;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::insert(int pos, bin_node* node, bin_node* leaf)
{
std::cout << "Node pos " << node->position << " Node Contact " << node->contact << " Leaf contact " << leaf->contact << " Leaf pos " << leaf->position << std::endl;
	if(pos < leaf->position)
	{
		if(leaf->left != NULL)
		{
			insert(pos, node, leaf->left);
		}
		else
		{
			std::cout << "New node added on left" << std::endl;
			leaf->left = node;
		}
	}
	else if(pos > leaf->position)
	{
		if(leaf->right != NULL)
		{
			insert(pos, node, leaf->right);
		}
		else
		{
			std::cout << "New node added on right" << std::endl;
			leaf->right = node;
		}
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
		//handles case if this the root left and right have not been used yet.
		if(b_root->left == 0 && n->position < b_root->position)
		{
			std::cout << "Left of root is " << n->contact << std::endl;
			b_root->left = n;
			counter++;
		}
		else if(b_root->right == 0 && n->position > b_root->position)
		{
			std::cout << "Right root is " << n->contact << std::endl;
			b_root->right = n;
			counter++;
		}
		else{
			insert(n->position, n, leaf);
			counter++;
		}
	}
}


void Bin_Tree::in_order(bin_node* n)
{
	if(n)
	{
		in_order(n->left);
		std::cout << "Contact " << n->contact << std::endl;
		in_order(n->right);

	}
}

