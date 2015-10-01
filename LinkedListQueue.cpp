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
		head = tail = new node;
		head->next = NULL;
		head->data = elem;
	}	
	else {
		tail->next = new node;
		tail->next = NULL;
		tail->data = elem;
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
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

#endif

