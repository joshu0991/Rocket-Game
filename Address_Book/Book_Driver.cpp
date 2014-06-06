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
	string url;
	string del_val;
	int op;
	bool ws;
	string phone;
	bool sav = false;
	std::string data;
	Linked_List_Func* l = new Linked_List_Func();
	Bin_Tree *bt = new Bin_Tree();
	Addr_Book b;
	bool finished = false;
	 cout << "loading..." << endl;
	 b.load_list_into_Memory(l);
	 b.construct_list(l);
	 bt->build_tree(l);
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
		 cout << "8) Print out number * Not working*" << endl;
		 cout << "9) Search book" << endl;
		 getline(cin, ops);
		 stringstream(ops) >> op;
//if(op <= 9 && op > 0)
//{
	switch(op)
	{

	//Add a contact
	case 1:
	{
		ws = true;
		while(ws == true){
		cout << "Enter the contact name " << endl;
		getline(cin, contact);
		ws = b.check_ws(contact);
		}
		ws = true;
		while(ws == true){
		cout << "Enter the phone number " << endl;
		getline(cin, phone);
		ws = b.check_ws(phone);
		}
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
		b.build_schedule(l);
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
		b.print_list_to_file(l, sav);
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
	}
	break;

	//Save changes
	case 7:
	{
		cout << "Saving..." << endl;
		sav = true;
		b.print_list_to_file(l, sav);
		cout << "Save was successful" << endl;
		sav = false;
	}
	break;

	case 8:
		{
			//cout << "Enter the URL" << endl;
			//getline(cin, url);
			//b.get_info(url);
			//add a new node with the entered url need new add method
			//yet to do. Possibly complete with Q(t)
		}
	break;
	case 9:
	{
		cout << "What would you like to seatch for? " << endl;
		getline(cin, data);
		cout << "Searching for " << data << endl;
		b.search(bt, data);
	}
	}
	//}
}
	l->~Linked_List_Func();
	bt->~Bin_Tree();
}


