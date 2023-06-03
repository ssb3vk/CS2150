//Sidhardh Burre, ssb3vk@virginia.edu, 3/25/2021, wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"
using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
// Sid: additionally we define some hashing structure here, first its
// the default hash set and then my own. 
#define MAXDIM 500
char grid[MAXDIM][MAXDIM];
//unordered_set <string> dictHash;
hashTable* dictHash; 

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
bool readInDict(string filename);
void wordFinder(int numRows, int numCols); 



int main(int argc, char* argv[]) {
  
  string dictFileName, gridFileName;
  int rows, cols;
 
  dictHash = new hashTable();
 
  dictFileName = argv[1]; 
  gridFileName = argv[2]; 

  bool result = readInGrid(gridFileName, rows, cols);

  if (!result) {
    cout << "Error reading in file!" << endl;
    return 1;

  }

  readInDict(dictFileName);
 
  wordFinder(rows, cols); 
  
  return 0;

}


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            
        }
        
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
    
}



bool readInDict(string filename) {
  ifstream file(filename);

  if(!file.is_open()) {
    return false;

  }

  int i = 0;
  string data, line; 
  
  while(getline(file, line)) {//go through the first time for length
    i++;
    
  }
  
  dictHash->setLoadFactor(0.5);//setting the load factor
  dictHash->sizer(i);//setting the desired size

  file.clear();//resetting the file for the next pass through 
  file.seekg(0); 
  
  while(getline(file, data)) {
    if (data.length() > 2) {
      dictHash->insert(data);  
      
    }
 
  }
  
  file.close();  
  
  return true;

}


void wordFinder(int numRows, int numCols) {
  int wordsFound = 0; 
  string ofInterest;//declaring this here because its possible to get "text" from "textsss" and "text"
  string gridWord;
  string prevWord; 
  
  for (int i = 0; i < numRows; i++) {//Row location iterator
    for (int j = 0; j < numCols; j++) {//Column location iterator
      for (int k = 0; k < 8; k++) {//Direction iterator     
	gridWord = getWordInGrid(i, j, k, 22, numRows, numCols);//setting the gridWord here allows a single call to getWordInGrid per direction per location

	for (int l = 3; l < 24; l++) {//iterating from word lengths 3 to 22
	  ofInterest = gridWord.substr(0, l);//substringing the grid word to our needed size
	   
	  //if the word we think is a word was valid in the previous iteration, we don't bother with it
	  //this is relevant near the edge when the getWordInGrid keeps returning the same word
	  // helps efficieny cause at the edges instead of iterating 20 times, it checks twice before breaking
	  
	  if (ofInterest == prevWord) {
	    break;

	  }
	  prevWord = ofInterest;//cause its a valid word we can now set it up so that it trips for the next iteration

	  
	  // checks if the word is in the hash set
	  if ( (dictHash->find(ofInterest)) ) {
	    
	    switch (k) { // used to output direction
            case 0:
	      cout << "N "; 
              break; // north
            case 1:
	      cout << "NE"; 
              break; // north-east
            case 2:
              cout << "E ";   
              break; // east
            case 3:
              cout << "SE";   
              break; // south-east
            case 4:
              cout << "S ";  
              break; // south
            case 5:
              cout << "SW";   
              break; // south-west
            case 6:
              cout << "W ";  
              break; // west
            case 7:
              cout << "NW";   
              break; // north-west
	      
	    }

	    cout << "(" << i << ", " << j << "): \t" << ofInterest << '\n';
	    
	    wordsFound++;
	    
	    }

	}
	  
      }

    }

  }

  cout << wordsFound << " words found" << endl;
  
  
}
	  
