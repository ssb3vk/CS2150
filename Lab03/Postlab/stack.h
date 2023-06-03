//Sidhardh Burre, ssb3vk@virginia.edu, 2/25/2021, stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"

using namespace std;

class stack {
 public:
  stack();
  ~stack();

  void push(int e);
  void pop();
  int top();
  bool empty() const;

private: 
List* list; 
ListItr* itr; 

};

#endif
  
  
