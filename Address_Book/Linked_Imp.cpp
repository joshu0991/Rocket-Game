/*
 * Linked_Imp.cpp
 *
 *  Created on: May 17, 2014
 *      Author: josh
 */



#include "Linked_List.h"

void Linked_List_Func::add_node_end(std::string contact, std::string phone, node* root)
{
	node* current;
	current = root;
		while(current->next != 0)
		{
			current = root->next;
		}
		current->next = new node;
		current->next = 0;
		current->contact = contact;
		current->phone = phone;
}

node* Linked_List_Func::add_first(std::string place, std::string phone)
{
	node* root;
	root = new node;
	root->contact = place;
	root->phone = phone;
	root->next = 0;
	return root;
}

void Linked_List_Func::traverse_List(node* root)
{

	node* current = root;

	while(current->next != 0)
	{
		std::cout << "Contact " + current->contact << std::endl;
		std::cout << "Phone " + current->phone << std::endl;
		current = current->next;
	}

}
