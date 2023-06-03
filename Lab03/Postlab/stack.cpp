//Sidhardh Burre, ssb3vk@virginia.edu, 2/25/2021, stack.cpp

#include <iostream>
using namespace std;

#include "stack.h"
#include "List.h"
#include "ListItr.h"

stack::stack() {
  list = new List();
  itr = new ListItr(list->last());

}

stack::~stack() {
  delete list;
  delete itr;

}

void stack::push(int e) {
  list->insertAtTail(e);

}

void stack::pop() {
  list->remove(); 

}

int stack::top() {
  if (itr != NULL) {
    delete itr;
  }

  itr = new ListItr(list->last());

  return itr->retrieve();

}

bool stack::empty() const {
  return list->isEmpty();

}
  
