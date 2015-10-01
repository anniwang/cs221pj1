//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

LinkedListQueue::LinkedListQueue()
{
	// intialize head and tail
	head = NULL;
	tail = NULL;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
	// if the queue is empty, a new node is added
	// the head and the tail both point to the new node
	if (is_empty()){
		node* temp = new node;
		temp->next = NULL;
		temp->data = elem;
		head = temp;
		tail = temp;
	}	
	// if the queue is not empty, a new node is added
	//	as the next node of the tail
	// the tail is then moved to the newly added node
	else {
		node* temp = new node;
		temp->next = NULL;
		temp->data = elem;
	
		tail->next = temp;
		tail = temp;
	}
}

PuzzleState *LinkedListQueue::take_out()
{
	// the queue must not be empty to take out an element
	assert(!is_empty());

	// store the data value into a variable to return
	PuzzleState* ret = head->data;

	// store the old node in a temporary variable 
	// move the head to point to the next node
	// delete the old node
	node* temp = head;
	head = head->next;
	delete temp;
	return ret;
}

bool LinkedListQueue::is_empty()
{
	return (head == NULL);
}

LinkedListQueue::~LinkedListQueue()
{
  	while (!is_empty()) {
		take_out();
	}
}

#endif

