#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from BagOfPuzzleStates.

/*
* queue will have front pointer and back pointer
* queue min array size = 2
*/


// constants
static const int INITIAL_QSIZE = 1000;

// global variables
int capacity;
int front;
int back;

//PuzzleState **array;


ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor

  array = new PuzzleState*[INITIAL_QSIZE];  // initialize queue
  capacity = INITIAL_QSIZE;                 // initialize capacity 
  // initialize front and back pointer
  front = 0;
  back = 0;

}

/*enqueue method*/
void ArrayQueue::put_in(PuzzleState *elem)
{
  // TODO: implement put_in method

  // ensure enough space
  //ensure_capacity(capacity+1);

  // put in
  array[back] = elem;

  // update back pointer
  back = (back+1) % capacity;
}


/*FIFO dequeue method*/
PuzzleState *ArrayQueue::take_out()
{
  // terminate if queue is empty
  assert(!is_empty());

  //cout << "arrayQ is dequeing" << endl;
  // store output value
  PuzzleState* output = array[front];
  
  //update front pointer
  front = (front+1) % capacity;

  return output; 
  // TODO: implement take_out method
}


/*check empty*/
bool ArrayQueue::is_empty()
{
  if(front == back) 
    return true;
  else
    return false;
  // TODO: implement is_empty method
}

// TODO: implement ensure_capacity (but leave this to last.. just
// start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
  // if not enough room in array
  // back = capacity-1 && head = 0 || front = back + 1
  if (capacity < n) {   

    // Make plenty of room.
    /* TODO: the larger of n and twice the current capacity */
    int target_capacity = (n > 2*capacity) ? n : (2*capacity);

    // TODO: Set the current array aside and make room for the new one.
    PuzzleState **oldarray = array;
    array = new PuzzleState*[target_capacity];

    // TODO: Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?
    for(int i = 0; i < back; i++){
      array[i] = oldarray[i];
      front = i;
    }

    // TODO: Fix front and back and capacity 
    // so they correspond to the new array.
    
    back = target_capacity;
    // front should be equal to i 
    // i.e. the element in the old array.


    // update capacity
    capacity = target_capacity;

    //-- add updates to front and back?

    // TODO: Delete the old array.
    delete [] oldarray;
  }
}


ArrayQueue::~ArrayQueue()
{
  // TODO: implement the destructor

  // do any cleanup like deallocating
  // any dynamically allocated memory

  delete [] array;
}

#endif

