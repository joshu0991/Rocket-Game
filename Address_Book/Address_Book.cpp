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

void Addr_Book::delete_contact(string cont_name, Linked_List_Func *l) {
	l->delete_node(cont_name);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::print_list_to_file(Linked_List_Func *l)
{
	node* n = l->get_root();
	ofstream fh("Address_Book.dat", ios::out | ios::binary);
	if(fh.is_open()){
	while(n!= 0)
	{
		std::cout << "Printing " + n->contact  << std::endl;
 		std::string contact = n->contact + "*";
		std::string phone = n->phone + "*";
		fh.write(contact.c_str(), contact.size());
		fh.write(phone.c_str(),  phone.size());
		n = n->next;
	}
	fh.close();
	}else{
		std::cout << "Cannot open file " << std::endl;
	}
	load_list_into_Memory(l);
}

std::string Addr_Book::load_list_into_Memory(Linked_List_Func *l)
{
	std::string data;
	ifstream ifh("Address_Book.dat", ios::in | ios::binary);
	if(ifh.is_open())
	{
		while(!ifh.eof())
		{
			data.append(1, ifh.get());
			std::cout << data <<std::endl;
		}
		ifh.close();
	}
	return data;

}
