/*
 * Stack.cpp
 *
 *  Created on: May 18, 2014
 *      Author: josh
 */




#include "Stack.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Stack::push(std::string contact, std::string phone)
{
	node* temp_top = top;
	node* new_top;
	if(top == 0)//stack is empty
	{
		new_top = new node;
		new_top->contact = contact;
		new_top->phone = phone;
		new_top->next = 0; //set the first created node to link to 0
		top = new_top;
	}else{
	new_top = new node;
	new_top->contact = contact;
	new_top->phone = phone;
	new_top->next = temp_top;
	top = new_top;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Stack::set_next(node* node)
{
	top = node;
}

Stack::Stack()
{
	top = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node* Stack::pop()
{
	node* node;
	node = top;
	top = top->next;
	return node;

}
