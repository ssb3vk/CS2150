//Header comment
//Sidhardh Burre, ssb3vk@virginia.edu, 2/6/2021, xToN.cpp

#include <iostream>
using namespace std;

//recursive functoin xton() that raises x to non-negative integers n

int xton (int x, int n) {
  if( n==0 ){
    return 1;
  }else{
    return x * xton(x, n-1);
  }
}

int main() {
  int x, n, xPowern;
  cin >> x;
  cin >> n;
  xPowern = xton(x, n);

  cout << xPowern << endl;

  return 0;

}
