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
	Link_Nodes(array, size);
	delete array;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//position is nodes sum of characters node is the next node to insert and leaf is
//initialized as the root and recursivly traverses left or right depending on which way way node
//needs to be inserted
void Bin_Tree::insert(int pos, bin_node* node, bin_node* leaf)
{
	if(pos < leaf->position) //if the position on the node is less than the position on the leaf go left
	{
		if(leaf->left != NULL) //if there is no node on the left
		{
			insert(pos, node, leaf->left); //recursivly call the insert function to advance the pointer left
		}
		else //add node to the left
		{
			leaf->left = node;
		}
	}
	else if(pos > leaf->position)
	{
		if(leaf->right != NULL) //if there is a node on the right
		{
			insert(pos, node, leaf->right); //recursivly call insert function to increase pointer to the right
		}
		else //add node to the right
		{
			leaf->right = node;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//link nodes in the array to each other in the appropriate order
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
			insert(n->position, n, leaf); //starts recursive calling of insert to add node in correct place
			counter++;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Traverse the left subtree. Visit the root.Traverse the right subtree.
void Bin_Tree::in_order(bin_node* n)
{
	if(n)//base case false when node is null
	{
		in_order(n->left); //add insert to system stack until all the way left
		std::cout << "Contact " << n->contact << std::endl; //once all the way left top is null pointer. top is popped and insert picks up by printing the contact from the node on top (furthest left)
		in_order(n->right); //pushes right tree until reaches null

	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Traverse the left subtree. Traverse the right subtree. Visit the root.
void Bin_Tree::post_order(bin_node* n)
{
	if(n)//base case false when node is null
	{
	post_order(n->left);//add insert to system stack until all the way left
	post_order(n->right); //pushes right tree until reaches null
	std::cout << "Contact " << n->contact << std::endl; //after all the left and all the way right prints out contact on top of system stack
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Visit the root. Traverse the left subtree. Traverse the right subtree
void Bin_Tree::pre_order(bin_node* n)
{
	if(n) //base case false when node is null
	{
		std::cout << n->contact << std::endl; //starts by printing root
		pre_order(n->left);//add insert to system stack until all the way left printing roots as it goes
		pre_order(n->right); //add insert to system stack until all the way

	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bin_Tree::add_node(bin_node* n)
{

}
