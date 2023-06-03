//Sidhardh Burre, ssb3vk@virginia.edu, 4/15/2021, threexinput.cpp
#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);//guaranteed to be a positive integer

int main(){
  timer subroutine; 

  int cInput;
  // prompt for input value
  cout << "Enter a number: ";
  cin >> cInput;

  int iter;
  // prompt for time test
  cout << "Enter iterations of subroutine: ";
  cin >> iter;

  int converge = threexplusone(cInput);

  subroutine.start(); 
  for (int i = 0; i < iter; i++) {
    threexplusone(cInput);

  }
  subroutine.stop();

  //double averageTime = (1000 * subroutine.getTime()) / iter; 
  //cout << "It took an average of " << subroutine.getTime() << " milliseconds for the subroutine" << endl; 
  
  cout << "Steps: " << converge << endl;

  return 0; 

}
