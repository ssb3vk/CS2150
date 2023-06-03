//Sidhardh Burre, ssb3vk@virginia.edu, 2/14/2021, List.cpp

#include <iostream>
using namespace std;

#include "List.h"

// The default constructor.
// It should initialize all private data members
// and set up the basic list structure with the dummy head and tail nodes.
List::List() {
  count = 0;
  head = new ListNode();
  tail = new ListNode();

  head->next = tail;
  tail->previous = head;

  head->previous = NULL;
  head->value = 0;
  
  tail->next = NULL; 
  tail->value = 0; 
}

// The copy constructor.
// It should create a **new** list of ListNodes whose contents
// are the same values as the ListNodes in `source`.

// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;

  //Making a deep copy
  //Sid: Making a copy of the ListItr object?
  //Sid: Wait its actually creating the list copy, I see. 
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }

  //no return? 

}


// The destructor.
// It should empty the list and reclaim the memory allocated in the constructor for head and tail.
//Sid: Shouldn't it also address the ListNodes? Or will they die automatically? 
List::~List() {
  makeEmpty();
  delete head;
  delete tail;

}

// Returns true if empty, else false
bool List::isEmpty() const {//Sid: easily implementable but imma hold off
  if (size() == 0) {
    return true;
  } else {
    return false;
  }

}

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
void List::makeEmpty() {
  ListItr ListItrObject = ListItr(this->head->next);//is there no way I can make first() const or something? 

  
  while(!ListItrObject.isPastEnd()) {
    ListItrObject.moveForward();
    delete ListItrObject.current->previous;
    //ListItrObject.current->previous = NULL; //is this fine? 
    
  }

  //delete ListItrObject.current->previous; 

  head->next = tail;
  tail->previous = head; //is this a valid implementation?

  this->count = 0;//setting count to 0
  
  return; 

}

//Returns an iterator that points to the first ListNode **after** the dummy had node (even on an empty list!)
ListItr List::first() {
  return ListItr(this->head->next);

}

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last() {
  return ListItr(this->tail->previous);

}

// Inserts x at tail of list
void List::insertAtTail(int x){
  ListNode* TailPreviousPlaceholder = tail->previous;
  
  tail->previous = new ListNode();
  tail->previous->value = x;
  
  tail->previous->next = tail;


  tail->previous->previous = TailPreviousPlaceholder; 
  TailPreviousPlaceholder->next = tail->previous;

  this->count++;

  return; 

}

// Removes the first occurrence of x
void List::remove() {//changed for stack implementation to just delete last node

  ListItr ListNodeRemove = last(); 

  if (ListNodeRemove.isPastEnd()) {
    return;
    
  } else {
    ListNodeRemove.current->previous->next = ListNodeRemove.current->next;
    ListNodeRemove.current->next->previous = ListNodeRemove.current->previous;
    delete ListNodeRemove.current; 
    this->count--;
    return;
    
  }

}

int List::size() const {
  ListItr ListItrObject = ListItr(this->head->next);//is there no way I can make first() const or something? 
  int size = 0; 
  
  while(!ListItrObject.isPastEnd()) {
    size++;
    ListItrObject.moveForward();
  }

  return size; 

}

