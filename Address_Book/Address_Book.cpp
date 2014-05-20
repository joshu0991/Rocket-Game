/*
 * Address_Book.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */



//#include "Linked_List.h"
#include "Addr_Book.h"
using namespace std;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::add_contact(string contact, string phone, Linked_List_Func *l)
{
	if(root == 0)
		{
			root = l->add_first(contact, phone);
		}else{
			l->add_node_end(contact, phone, root);
		}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Addr_Book::Addr_Book()
{
	root = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::print_list_to_screen(Linked_List_Func *l)
{
	l->traverse_List(root);

}
