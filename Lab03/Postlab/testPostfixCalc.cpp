#include <iostream>
#include "postfixCalculator.h"
//using  std::cout;
//using std::endl;
using namespace std; 

int main() {

  string token;
  postfixCalculator *calculator = new postfixCalculator(); 
  
  while ( cin >> token) {
    if ( token == "+" ) {
      calculator->add();
      
    } else if (token == "-") {
      calculator->sub();

    } else if (token == "*") {
      calculator->mult();

    } else if (token == "/") {
      calculator->div();

    } else if (token == "~") {
      calculator->neg();

    } else {
      calculator->pushPF(stoi(token) );
      
    }
  }

  cout << calculator->topPF() << endl;

  delete calculator; 

  return 0; 

}
