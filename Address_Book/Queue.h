/*
 * Queue.h
 *
 *  Created on: May 18, 2014
 *      Author: josh
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include "node.h"
class Queue
{
public:
	Queue();
	void enque(std::string, std::string); //add node to queue with string contact and phone number
	node* deque(); //remove first node (FIFO) and return the node so the data get be obtained
	void find_end();
private:
	node* head;
	node* end;
};



#endif /* QUEUE_H_ */
