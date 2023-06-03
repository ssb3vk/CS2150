//Sidhardh Burre, ssb3vk@virginia.edu, 3/6/2021, prelab4.cpp

#include <iostream>
#include <climits> //Used for overflow()
using namespace std;

union unsignedIntToBoolean {
  unsigned int u;
  int x;
} converter; 

void sizeOfTest();

void overflow();

void outputBinary(unsigned int x);

int main(){
  unsigned int x;
  cin >> x;
  
  sizeOfTest();
  overflow();
  outputBinary(x);

  return 0;

}

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;

  return;

}

void overflow() {
  unsigned int x = UINT_MAX;
  unsigned int sum = x + 1; 

  cout << x << " + " << " 1 " << "= " << sum << endl;
  
  return;

}

void outputBinary(unsigned int x) {//converting x to a binary representation
  int boolRep[32] = {0};
  int y = 1;
  int q;
  int r; 
  
  for( int i = 0; i < 32; i++) {
    q = x / 2;
    r = x % 2;

    x = q;
    //cout << "boolRep[" << i << "] before: " << boolRep[i] << endl; 
    boolRep[i] = r;
    //cout << "boolRep[" << i << "]  after: " << boolRep[i] << endl; 
    if ( q == 0 ) {
      break;

    }


  }
   
  for( int i = 31; i > -1; i --) {
    cout << boolRep[i];
    if ( i == 4 || i == 8 || i == 12 || i == 16 || i == 20 || i == 24 || i == 28 ){
      cout << " ";
      
    }
    
  }

  cout << endl; 
  
  return;

}
