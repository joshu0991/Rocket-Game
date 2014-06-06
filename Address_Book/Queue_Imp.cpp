/*
 * Queue_Imp.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */




#include "Queue.h"

void Queue::enque(std::string contact, std::string phone)
{
	node* new_node;
	if(head == 0) //create first
	{
		new_node = new node;
		new_node->contact = contact;
		new_node->phone = phone;
		new_node->next = 0;
		head = new_node;
	}else{
		new_node = new node;
		new_node->contact = contact;
		new_node->phone = phone;
		find_end();
		end->next = new_node;
		new_node->next = 0;
	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

node* Queue::deque()
{
	node* d_node;
	d_node = head;
	head = head->next;
	return d_node;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Queue::Queue()
{
	head = 0;
	end = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Queue::find_end()
{
	node* node;
	node = head;
	while(node->next != 0)
	{
		node = node->next;
	}
	end = node;
}
