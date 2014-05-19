/*
 * Linked_List_Driver.cpp
 *
 *  Created on: May 17, 2014
 *      Author: josh
 */

#include "Linked_List.h"
//crappy program to test the linked list
/*
int main() {
	Linked_List_Func ll;
	node *root;
	bool first = true;
	std::string contact;
	std::string phone;
	std::string op;
	bool finished = false;
	while (finished != true) { //get input
		std::cout << "enter the contact" << std::endl;
		std::getline(std::cin, contact);
		std::cout << "enter the phone number" << std::endl;
		std::getline(std::cin, phone);
		if (first == true) //first node
		{
			root = ll.add_first(contact, phone);
			first = false;
		} else { //if it isn't the first node
			ll.add_node_end(contact, phone, root);
		}
		std::cout << "Enter 1 to terminate 2 to add node and 3 to print out list" << std::endl;
		std::getline(std::cin, op);
		if(op == "1")
		{
			finished = true;
			continue;
		}else if(op == "2"){
			finished = false;
			continue;
		}else if(op == "3"){
			ll.traverse_List(root);
		}else{
			finished = true;
		}

		}
}
*/
