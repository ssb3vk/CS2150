//Sidhardh Burre, ssb3vk@virginia.edu, 4/20/2021, heap.h

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "element.h"
using namespace std;

class heap {
 public:
  heap();// constructor
  ~heap();// destructor

  void insert(element* e); //insert for putting in the Huffman tree
  element* findMin();
  element* deleteMin();
  unsigned int size();// returns heap size
  void makeEmpty();
  bool isEmpty();
  void print();

 private:
  vector<element*> container;// this is how we're holding our heap
  unsigned int heap_size;

  void percolateUp(int hole);
  void percolateDown(int hole);

};

#endif
  
