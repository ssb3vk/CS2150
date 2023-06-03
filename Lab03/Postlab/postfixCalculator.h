//Sidhardh Burre, ssb3vk@virginia.edu, 2/25/2021, postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"

class postfixCalculator {

 public:
  postfixCalculator();
  ~postfixCalculator();

  void popPF();
  int topPF();
  void pushPF(int x);
  void isEmptyPF(); 
  
  void add();
  void sub();

  void mult();
  void div();
  void neg();

  void intGiver(int* var);

 private:
  stack* PFstack; 
  
};

#endif
