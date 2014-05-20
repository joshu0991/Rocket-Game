/*
 * Book_Driver.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */

#include "Addr_Book.h"
#include <sstream>
using namespace std;
int main()
{
	string contact;
	string ops;
	int op;
	string phone;
	Linked_List_Func* l = new Linked_List_Func();

	Addr_Book b;
	bool finished = false;
	while(!finished)
	{
		 cout << "What would you like to do? " << endl;
		 cout << "1) Add a new contact" << endl;
		 cout << "2) Delete a contact " << endl;
		 cout << "3) Build a Daily Schedule " << endl;
		 cout << "4) Print out all contents " << endl;
		 getline(cin, ops);
		 stringstream(ops) >> op;
	switch(op)
	{

	case 1:
	{
		cout << "Enter the contact name " << endl;
		getline(cin, contact);
		cout << "Enter the phone number " << endl;
		getline(cin, phone);
		b.add_contact(contact, phone, l);
	}
		break;
	case 2:


	break;

	case 3:


	break;

	case 4:
	b.print_list_to_screen(l);
	break;
	}
	}
}


