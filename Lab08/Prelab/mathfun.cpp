// Sidhardh Burre, ssb3vk@virginia.edu, 4/8/2021, mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long); 

int  main () {

  // declare the local variables
  long  x, y, prod, pow;

  // taking in the first value
  cout << "Enter integer 1: ";
  cin >> x;

  // taking in the second value
  cout << "Enter integer 2: ";
  cin >> y; 

  // Calculate x*y and print out results
  prod = product(x, y);
  cout << "Product: " << prod << endl;

  // Calculate x^y and print out the results
  pow = power(x, y);
  cout << "Power: " << pow << endl; 

  // all done!
  return 0;
  
}
