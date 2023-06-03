//Sidhardh Burre, ssb3vk@virginia.edu, 3/25/2021, hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class hashTable {

 public:
  hashTable(/*double loadFactor*/);
  ~hashTable();

  bool insert(string s);
  bool collisionResolution(string s, int location); //decides what to do if it collides (makes it easy to change between hashing methods)
  
  //bool delete(string s); //Is this even needed? 
  bool find(string s);

  void sizer(int i); //sets the size of the vector within the hashTable
  bool checkprime(unsigned int p); 
  int getNextPrime(unsigned int n); 
	
	
  unsigned int locationCalc(string s); 	
  unsigned int hashFunction1(string s);//some hashing function
  unsigned int hashFunction2(string s);//another different hashing function

  void setLoadFactor(double d); //sets the desired loadFactor

 private:
  //can't be a string* array pointer cause arrays are dumb and don't work like that
  //instead we can just resize the vector to the size we need (dictionary size) and avoid the
  // costly copies. 
  vector<string>* table; 
  double loadFactorValue;
  int size;
  int elements; 
  int maxInsert; 

};

#endif

