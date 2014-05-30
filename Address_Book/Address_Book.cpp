/*
 * Address_Book.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */

//#include "C:\Python34\include\Python.h"
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

void Addr_Book::print_list_to_file(Linked_List_Func *l, bool sav)
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
	if(sav == false)
	{
	l->~Linked_List_Func(); //explicitly call dest. ... not sure if that is a good thing
	l->set_root(0); //delete the list
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::load_list_into_Memory(Linked_List_Func *l)
{
	std::string str;
	ifstream ifh("Address_Book.dat", ios::in | ios::binary);
	if(ifh.is_open())
	{
		while(!ifh.eof())
		{
			str.append(1, ifh.get());
		}
		ifh.close();
	}

	data = str;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::construct_list(Linked_List_Func *l) {
	int cof = 0;
	std::string contact = "";
	std::string phone = "";
	for (unsigned int i = 0; i < data.length(); i++) {
		char a = data[i];
		if (a != '*' && cof == 0) {
			contact += a;
		} else if (a == '*' && cof == 0) {
			cof++;
		} else if (a != '*' && cof == 1) {
			phone += a;
		} else if (a == '*' && cof == 1) {
			if (l->check_root()) {
				l->add_first(contact, phone);
				contact = "";
				phone = "";
			} else {
				l->add_node_end(contact, phone);
				contact = "";
				phone = "";
			}
			cof--;
		}

	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Addr_Book::build_schedule(Linked_List_Func *l)
{
	int size = calc_size(l);
	int rand = gen_number(size);
	std::cout << "Rand " << rand << " Size " << size << std::endl;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int Addr_Book::gen_number(int size)
{
	int random_num = 0;
	srand((unsigned)time(0));//seed random number generator
	random_num = (rand()%size)+1;
	return random_num;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int Addr_Book::calc_size(Linked_List_Func *l)
{
	int size = l->calc_size();
	return size;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//start a python script that will go to a web page and get phone and contact info
/*
void Addr_Book::get_info(std::string URL)
{
	Py_SetProgramName('URL_Builder.py');
	Py_Initialize();
	PyRun_SimpleString("from time import time,ctime\n print('Today is',ctime(time())\n)");
	Py_Finalize();
	//execute python script
}
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
void Addr_Book::email_list(Linked_List_Func *l)
{
	//pass list to python program
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool Addr_Book::check_ws(std::string input)
{
	bool tof = false;
	int a = input.length() - 1;
	if(isspace(input[a]) || isspace(input[0]))
	{
		tof = true;
		std::cout << "Whitespace detected Try input again." << std::endl;
	}
	return tof;

}
