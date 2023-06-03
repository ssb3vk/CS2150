//Sidhardh Burre, ssb3vk@virgina.edu, 4/20/2021, element.h

#ifndef ELEMENT_H
#define ELEMENT_H

class element {
 public:
  element();//default constructor
  element(char c, int f); 
  ~element(); 
  
  char character;
  int frequency; //or priority
  
  element* right; 
  element* left; 

};

#endif
