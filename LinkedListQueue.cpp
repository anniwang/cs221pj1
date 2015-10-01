//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

LinkedListQueue::LinkedListQueue()
{
	head = NULL;
	tail = NULL;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
	if (is_empty()){
		node* temp = new node;
		temp->next = NULL;
		temp->data = elem;
		head = temp;
		tail = temp;
	}	
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
	assert(!is_empty());
	PuzzleState* ret = head->data;
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

