#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;

#include "postfixCalculator.h"

int main() {

  string token;
  postfixCalculator *calculator = new postfixCalculator(); 
  
  while ( cin >> token) {
    if ( token == "+" ) {
      calculator->add();
      
    } else if (token == "-") {
      calculator->sub();

    } else {
      calculator->pushPF(stoi(token) );
      
    }
  }

  cout << calculator->topPF() << endl;

  delete calculator; 

  return 0; 

}
