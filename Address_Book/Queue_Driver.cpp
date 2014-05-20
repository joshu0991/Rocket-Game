/*
 * Queue_Driver.cpp
 *
 *  Created on: May 19, 2014
 *      Author: josh
 */


#include "Queue.h"
using namespace std;
int main()
{
	Queue q;
	string contact;
	string phone;
	string op;
	node* r;
	bool finished = false;

	while(finished == false)
	{
		cout << "1) enque or 2)deque" <<endl;
		getline(cin, op);
		if(op == "1"){
		cout << "Enter the contact name " << endl;
		getline(cin, contact);
		cout << "Enter the phone number " << endl;
		getline(cin, phone);
		q.enque(contact, phone);
		}else if(op == "2")
		{
		r = q.deque();
		cout << "Contact " + r->contact << endl;
		cout << "Phone " + r->phone <<endl;
		}
	}

}
/*
 * Todo
 * Deal with deque from enpty queue
 */
