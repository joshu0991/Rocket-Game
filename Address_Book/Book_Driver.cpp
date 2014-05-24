/*
 * Book_Driver.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */

#include "Addr_Book.h"
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
	string contact;
	string ops;
	string del_val;
	int op;
	string phone;
	Linked_List_Func* l = new Linked_List_Func();

	Addr_Book b;
	bool finished = false;
	 cout << "loading..." << endl;
	 b.load_list_into_Memory(l);
	 b.construct_list(l);
	 cout << "Loading completed" << endl;
	while(!finished)
	{
		 cout << "What would you like to do? " << endl;
		 cout << "1) Add a new contact" << endl;
		 cout << "2) Delete a contact " << endl;
		 cout << "3) Build a Daily Schedule" << endl;
		 cout << "4) Print out all contents " << endl;
		 cout << "5) Save changes and exit " << endl;
		 cout << "6) Do not save changes and exit " << endl;
		 cout << "7) Save changes" << endl;
		 cout << "8) Reload program" << endl;
		 getline(cin, ops);
		 stringstream(ops) >> op;
	switch(op)
	{

	//Add a contact
	case 1:
	{
		cout << "Enter the contact name " << endl;
		getline(cin, contact);
		cout << "Enter the phone number " << endl;
		getline(cin, phone);
		b.add_contact(contact, phone, l);
	}
	break;

	//Delete a contact
	case 2:
	{
		cout << "Enter the contact name to delete" << endl;
		getline(cin, del_val);
		b.delete_contact(del_val, l);
	}
	break;

	//Build a tentative schedule
	case 3:
	{
		cout << "not started" << endl;
	}
	break;

	//Print what is in the list
	case 4:
	{
	b.print_list_to_screen(l);
	}
	break;

	//save and exit program
	case 5:
	{
		cout << "Saving..." << endl;
		b.print_list_to_file(l);
		finished = true;
		cout << "Save was successful" << endl;
		cout << "Exiting ..." << endl;
		exit(0);
	}
	break;

	//Exit program without saving
	case 6:
	{
		finished = true;
		cout << "Exiting ..." << endl;
		exit(0);
	}
	break;

	//Save changes
	case 7:
	{
		cout << "Saving..." << endl;
		b.print_list_to_file(l);
		cout << "Save was successful" << endl;
	}
	break;

	//reload the program
	case 8:
		{
		cout << "loading..." << endl;
		b.load_list_into_Memory(l);
		b.construct_list(l);
		cout << "Loading completed" << endl;
		}

	}
	}
}



