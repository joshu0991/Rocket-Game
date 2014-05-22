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
	node* r = l->get_root();
	if(r == 0)
		{
			 l->add_first(contact, phone);
		}else{
			l->add_node_end(contact, phone);
		}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Addr_Book::Addr_Book()
{

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::print_list_to_screen(Linked_List_Func *l)
{
	l->traverse_List();

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//Doesn't work after I changed the set up
void Addr_Book::delete_contact(string cont_name, Linked_List_Func *l) {
	l->delete_node(cont_name);
}
