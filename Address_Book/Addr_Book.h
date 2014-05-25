/*
 * Addr_Book.h
 *
 *  Created on: May 17, 2014
 *      Author: josh
 */

#ifndef ADDR_BOOK_H_
#define ADDR_BOOK_H_
#include "node.h"
#include "Linked_List.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
class Addr_Book : public Linked_List_Func //the idea to inherit the class came as an after thought :( putting it here to remind myself for next time.
{
public:
	Addr_Book();
	std::string data;
	void add_contact(std::string, std::string, Linked_List_Func *l); //Just want to pass around an a ptr to something in the heap :)
	void delete_contact(std::string contact, Linked_List_Func *l);
	void build_schedule(Linked_List_Func *l);
	void print_list_to_file(Linked_List_Func *l);
	void load_list_into_Memory(Linked_List_Func *l);
	void print_list_to_screen(Linked_List_Func *l);
	void construct_list(Linked_List_Func *l);
	int gen_number(int);
	int calc_size(Linked_List_Func *l);

};



#endif /* ADDR_BOOK_H_ */
