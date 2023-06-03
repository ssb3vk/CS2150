//Sidhardh Burre, ssb3vk@virginia.edu, 3/25/2021, hashTable.cpp

#include <iostream>
#include <vector>
#include <math.h>
#include "hashTable.h"
using namespace std;

hashTable::hashTable() {
  table = nullptr;// no sizing, will be done later 
  
  loadFactorValue = 1;//by default this will be set to 1
  size = 0;
  elements = 0;
  maxInsert = 0; 
  
}

hashTable::~hashTable() {
  delete table;
  
}

bool hashTable::insert(string s) {
  int location = locationCalc(s);
  if ( (*table)[location] == "") {
    (*table)[location] = s; 
    return true; 
    
  } else {
    return collisionResolution(s, location); 

  }
 
  
}

// Pre-lab: linear
// Post-lab: double hash
bool hashTable::collisionResolution(string s, int location) {
  unsigned int f2 = hashFunction2(s);
  int maxInsertIterator = 0; 
  while (true) {
    //maxInsertIter is +1'd before being used 
    int place = (location + (f2 * ++maxInsertIterator) ) % size; 
    
    if ((*table)[ place ] == "") {  
      if (maxInsertIterator > maxInsert) {
	maxInsert = maxInsertIterator + 1;

      }
      (*table)[place] = s; 
      return true;
      
    }
    
  }

  return false; 

}

bool hashTable::find(string s) {
  int location = locationCalc(s); 
  unsigned int f2 = hashFunction2(s); 
  
  if (s == (*table)[location] ) {
    return true;

  } else {
    int place; 
    for (int i = 1; i < maxInsert; i++) {
      place = (location + (f2 * i) ) % size; 
      if ( (*table)[ place ] == "" ) {//if our find comes upon an empty spot we can exit
	return false;

      } else if ( (*table)[ place ] == s ){
	return true;

      } 

    }

    return false;

  }

}

void hashTable::sizer(int i) {
  elements = i;//setting the number of elements
  
  size = getNextPrime(elements/loadFactorValue);
  table = new vector<string>; 
  table->resize(size);

}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

unsigned int hashTable::locationCalc(string s) {
  return (hashFunction1(s)) % size;

}

//These hashing functions were inspired by the functions at the following website: 
//http://www.cse.yorku.ca/~oz/hash.html

unsigned int hashTable::hashFunction1(string s) {
  int i = 0;  
  unsigned int val = 0;
  for(char c : s) {
    val += static_cast<unsigned int>(c) + (i << 7) - (i << 3);//change these
    i++;
    
  }
  
  return val; 
  
}

unsigned int hashTable::hashFunction2(string s) {
  int i = 0;
  unsigned int val = 0; 
  for (char c : s) {
    val+= static_cast<unsigned int>(c) + (i << 5) + i;//change these
    i++;
    
  }

  return val; 

}

void hashTable::setLoadFactor(double d) {//essentialy a setter for the loadFactorValue
  loadFactorValue = d;  

}
