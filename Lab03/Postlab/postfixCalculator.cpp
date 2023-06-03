//Sidhardh Burre, ssb3vk@virginia.edu, 2/25/2021, postfixCalculator.cpp

#include <iostream>
#include "stack.h"
//using std::cout;
//using std::cin;
using namespace std; 

#include "postfixCalculator.h"

postfixCalculator::postfixCalculator() {
  PFstack = new stack; 
}

postfixCalculator::~postfixCalculator() {
  delete PFstack; 
}

void postfixCalculator::popPF() {
  isEmptyPF();
  PFstack->pop();

}

int postfixCalculator::topPF() {
  isEmptyPF();
  int r = PFstack->top();
  return r;
  
}

void postfixCalculator::pushPF(int x) {
  PFstack->push(x);

}

void postfixCalculator::isEmptyPF() {
  if(PFstack->empty()) {
    cout << "the stack is empty" << endl;
    exit(-1);

  } else {
    return;

  }

}

void postfixCalculator::add() {
  int a, b;
  intGiver(&a);
  intGiver(&b);

  pushPF(a + b);

}

void postfixCalculator::sub() {
  int a, b;
  intGiver(&a);
  intGiver(&b);

  pushPF(b - a);

}

void postfixCalculator::mult() {
  int a, b;
  intGiver(&a);
  intGiver(&b);

  pushPF(a * b);

}

void postfixCalculator::div() {
  int a, b;
  intGiver(&a);
  intGiver(&b);
  
  pushPF(b / a);

}

void postfixCalculator::neg() {
  int a;
  intGiver(&a);

  pushPF(-1 * a);

}

void postfixCalculator::intGiver(int* var) {
  *var = topPF();
  popPF();

}
