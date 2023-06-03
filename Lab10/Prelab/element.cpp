//Sidhardh Burre, ssb3vk@virginia.edu, 2/14/2021, element.cpp

#include <iostream>
#include "element.h"

using namespace std;

element::element() {
  character = '^';//empty character, interior node for huffman tree
  frequency = 0;
  right = NULL;
  left = NULL;

}

element::element(char c, int f) {// this is how we make our "normal nodes"
  character = c;
  frequency = f;

  right = NULL;
  left = NULL; 

}

element::~element() {// destructor, from BST lab 
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
