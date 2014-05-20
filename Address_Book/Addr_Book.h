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
class Addr_Book
{
public:
	Addr_Book();
	void add_contact(std::string, std::string, Linked_List_Func *l); //Just want to pass around an a ptr to something in the heap :)
	void delete_contact(std::string contact);
	void build_schedule();
	void print_list_to_file();
	void load_list_into_Memory();
	void print_list_to_screen(Linked_List_Func *l);
private:
	node* root;
};



#endif /* ADDR_BOOK_H_ */
