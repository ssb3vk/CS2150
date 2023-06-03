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

// The copy assignment operator.
// It should copy the contents of every ListNode in `source`
// into an **existing** list (the reference to the calling List object itself).

//Called when code looks something like list2 = list1;
List& List::operator=(const List& source) {
  if (this == &source) {
    //the two are the same list, no need to do anything
    return *this;
  } else {
    //clear out anything List2 contained
    //prior to copying over
    makeEmpty();

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;

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

//For both inserts, the harness handles for invalid inserts (insertAfter while at tail, vice versa) 
 
// Inserts x after current iterator position
void List::insertAfter(int x, ListItr position) {//gonna hold off on implementing these two have some questions
  //ListNode newListNode = ListNode(x);

  ListNode* TargetNextPlaceholder = position.current->next; //creating a placeholder cause otherwise bridging from the other side will be dificult

  position.current->next = new ListNode();
  position.current->next->value = x;

  TargetNextPlaceholder->previous = position.current->next;

  position.current->next->previous = position.current;
  position.current->next->next = TargetNextPlaceholder; 

  this->count++;
    
  return;

}

// Inserts x before current iterator position
void List::insertBefore(int x, ListItr position) {
  
  ListNode* TargetPreviousPlaceholder = position.current->previous;

  position.current->previous = new ListNode();
  position.current->previous->value = x;

  TargetPreviousPlaceholder->next = position.current->previous;

  position.current->previous->next = position.current;
  position.current->previous->previous = TargetPreviousPlaceholder; 

  this->count++;
    
  return;

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


// Returns an iterator that points to the first occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x) {
  ListItr ListItrObject = first();

  while (ListItrObject.retrieve() != x && !ListItrObject.isPastEnd()) {
    ListItrObject.moveForward();
  }

  return ListItrObject;

}

// Removes the first occurrence of x
void List::remove(int x) {//deleting the object you remove is kind of important, made a headache 

  ListItr ListNodeRemove = find(x);

  if (find(x).isPastEnd()) {
    //cout << "You're element wasn't found so nothing will be deleted" << endl; //is this fine? Protecting from deleting?-Just return, no output
    //will probably need to delete later and just return. 
    return;
    
  } else {
    
    ListNodeRemove.current->previous->next = ListNodeRemove.current->next;
    ListNodeRemove.current->next->previous = ListNodeRemove.current->previous;
    delete ListNodeRemove.current; 
    this->count--;
    return;
    
  }

}

// Returns the number of elements in the list
int List::size() const {
  ListItr ListItrObject = ListItr(this->head->next);//is there no way I can make first() const or something? 
  int size = 0; 
  
  while(!ListItrObject.isPastEnd()) {
    size++;
    ListItrObject.moveForward();
  }

  return size; 

}
