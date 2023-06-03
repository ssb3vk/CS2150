//Sidhardh Burre, ssb3vk@virginia.edu, 3/6/2021, bitCounter.cpp

#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <typeinfo>

using namespace std;

int rBitCounter(int q);

void baseConverter(string input, int iBase, int oBase);

void baseTenConverter(int input, int outputBase); 

int main(int argc, char **argv) {
  if ( argc == 1 ) {
    cout << "No command line arguments were given, exiting" << endl;

  } else {
  cout << argv[1] << " has " <<  rBitCounter(stoi(argv[1])) << " bit(s)" << endl; 
  cout << argv[2] << " (base " << argv[3] << ") = ";
  baseConverter(argv[2], stoi(argv[3]), stoi(argv[4])); 
  cout << " (base " << argv[4] << ")" << endl; 

  }
  return 0;

}

void baseConverter(string input, int iBase, int oBase) {
  int value; 
  for (int i = 0; i < input.length(); i++) {
    if (isalpha(input[i])) {
      value += (input[i] - '7') * pow(iBase , (input.length() - 1) - i);

    } else {
      value += (input[i] - '0') * pow(iBase , (input.length() - 1) - i);

    }
    
  }

  baseTenConverter(value, oBase); 

  return;
}

void baseTenConverter(int input, int outputBase) {
  string outputHolder; 
  char converter;
  int r = input%outputBase;

  if ( r < 10 ) {
    converter = (char) '0' + r;

  } else {
    converter = (char) '7' + r;

  }

  if ( input/outputBase == 0 ) {
    outputHolder += converter;
    cout << outputHolder;
    return; 

  } else {
    outputHolder += converter; 
    baseTenConverter(input/outputBase, outputBase);
    
  }

  cout << outputHolder;

}


int rBitCounter(int q) {
  if ( q == 0) {
    return 0;

  } else if ((q % 2) == 0) {
    return rBitCounter((int)q / 2);
    
  } else {
    return 1 + rBitCounter((int) q / 2);
    
  }
  
}
