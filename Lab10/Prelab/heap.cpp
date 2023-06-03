//Sidhardh Burre, ssb3vk@virginia.edu, 4/20/2021, heap.cpp

#include <iostream>
#include "heap.h"
#include "element.h"
using namespace std;

heap::heap() : heap_size(0) {
  element*c = new element('A', 0); 
  container.push_back(c);//why push back an element? Nobody knows.
  // pretty sure its to expand the vector by one so that we are 1-indexed
  // instead of 0-indexed
}

heap::~heap() {// our destructor method
  for (int i = 0; i < heap_size; i++) {// just iterate through the heap deleteing everything
    delete container[i];
    // used the BST-based delete method, no need to recurs through children
  }

}

void heap::insert(element* f) {// places an element onto the heap
  container.push_back(f);
  percolateUp(++heap_size);

}

void heap::percolateUp(int hole) {// restructure the tree to maintain ordering property, paired with insert
  element* x = container[hole];

  for ( ; (hole > 1) && (x->frequency < container[hole/2]->frequency); hole /= 2) {
    container[hole] = container[hole/2];
  }

  container[hole] = x;

}

element* heap::deleteMin() {// deletes the top node, minimum priority(frequency)
  if (heap_size == 0) {
    throw "deleteMin() called on empty heap";

  }

  element* ret = container[1];

  container[1] = container[heap_size--];

  container.pop_back();

  if (!isEmpty()) {
    percolateDown(1);

  }

  return ret;
}

void heap::percolateDown(int hole) {// percolates down, paired with delete
  element *x = container[hole];

  while (hole*2 <= heap_size) {
    int child = hole*2;

    if ((child+1 <= heap_size) && ((container[child+1]->frequency) < (container[child]->frequency))) {
      child++;
    }

    if (x->frequency > container[child]->frequency) {
      container[hole] = container[child];
      hole = child;
    } else {
      break;
    }
  }

  container[hole] = x;

}

element* heap::findMin() {// outputs a pointer to the min node
  if (heap_size == 0) {
    throw "findMin() called on empty heap";
  }
  return container[1];
}

unsigned int heap::size() {// gives the HEAP SIZE not vector size (heap size+1)
  return heap_size;
}

void heap::makeEmpty() {// just makes the heap empty ig. 
  heap_size = 0;
  container.resize(1);
}

bool heap::isEmpty() {
  return heap_size == 0;
}

void heap::print() {// print method for testing, kind of weird with lots of values. 
  cout << "(" << container[0]->character << ")" << endl;
  for (int i = 1; i <= heap_size; i++) {
    cout << "(" << container[i]->character << ", " << container[i]->frequency << ")";
    bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
    if (isPow2) {
      cout << endl << "\t";
    }
  }
  cout << endl;
}

  
