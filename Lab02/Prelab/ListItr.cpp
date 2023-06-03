//Sidhardh Burre, ssb3vk@virginia.edu, 2/14/2021, ListItr.cpp

#include <iostream>
using namespace std;

#include "ListItr.h"

// Constructors
ListItr::ListItr(){//I'm not sure how to implement the default constructor. Doesn't the List object need to set the "current" to head?

}

ListItr::ListItr(ListNode* theNode){
  current = theNode;

}

// Returns true if the iterator is currently pointing past the end position
// in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const {
  if(current->next == NULL){
    return true;
  }else{
    return false;
  }

}


// Returns true if the iterator is currently pointing past (before) the first position
// in list (i.e., it's pointing to the dummy head), else false
bool ListItr::isPastBeginning() const {
  if(current->previous == NULL){
    return true;
  }else{
    return false;
  }

}


// Advances `current` to the next position in the list (unless already past the end of the list)
void ListItr::moveForward() {
  if(isPastEnd()) {
    return;
  }else{
    current = current->next;//might be problematic, may need to juggle pointers
    return; 
  }
  
}


// Moves `current` back to the previous position in the list (unless already past the beginning of the list)
void ListItr::moveBackward() {
  if(isPastBeginning()){
    return;
  }else{
    current = current->previous;//same in-line comment as above (two comments up)
    return; 
  }

}


// Returns the value of the item in the current position of the list
int ListItr::retrieve() const {
  return this->current->value;

}


//Non-member functions:

// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!
void printList(List& source, bool forward) {
   
  if(forward) {
    ListItr ListItrObject = source.first();
    
    while(! ListItrObject.isPastEnd()){
      cout << ListItrObject.retrieve() << " "; 
      ListItrObject.moveForward();
    }

    cout << endl; 
    
  }if(!forward) {
    ListItr ListItrObject = source.last();

    while (! ListItrObject.isPastBeginning()){
      cout << ListItrObject.retrieve() << " ";
      ListItrObject.moveBackward();
    }

    cout << endl; 

  }

  // else{
  //  cout << "Mane how did you input a boolean that was neither true nor false?" << endl;
  //}

}
      
