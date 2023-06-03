//Sidhardh Burre, ssb3vk@virginia.edu, 4/20/2021, huffmanenc.cpp
// Some parts of this code come from the slides

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include "heap.h"

using namespace std; 

heap bh;// declaring a static binary heap
unordered_map<char, string> key;// static key map to store our char/code pairs
int symbols = 0;// number of letters within the file
int distinctSymbols = 0; // number of unique letters
int finalBits = 0; //bit counter of final file (adds up 1s and 0s)


// Forward declarations
bool readInput(string filename); //both reads in input and puts into bh
bool HuffmanTree(); //creates Huffman Tree
void prefixCodes(element* e, string path_taken); //generates prefix codes
void encoder(string filename); //encodes the text file into the Huffman code
void statistics(); //gives us our statistics


int main(int argc, char**argv) {
  if (argc != 2) {//just error checking here
    cout << "Must supply the input file name as the one and only parameter" << endl;
  }

  string inputFileName = argv[1]; // getting the file name

  readInput(inputFileName); // calling our readInput function on the file name that also puts it into our binary heap

  HuffmanTree(); // creates a huffman tree from the heap 

  prefixCodes(bh.findMin(), ""); //calling our recursive function to generate the prefix codes

  cout << "----------------------------------------" << endl;//separator

  encoder(inputFileName); // converts the file's characters into our coded format

  cout << "----------------------------------------" << endl;//separator

  statistics(); // generates our statistics

  delete bh.findMin(); // bh itself is statically allocated only the actual nodes need to be deleted as they are dynamically allocated

  return 0;

}

bool readInput(string filename) {
  int freq[256];//creating the array to hold frequency counts
  ifstream file(filename);//creating a file object

  if (!file.is_open()) {//error checking
    cout << "Unable to open '" << filename << "' for reading" << endl;
    exit(2);
  }

  for (int i = 0; i < 256; i++) {//setting the frequency array's values to 0
    freq[i] = 0;
  }

  char g;
  while (file.get(g)) {// for loop to read in the file and find frequencies
    unsigned char c = (unsigned char) g; 
    if ( ( c < ' ')/*32*/ || ( c > '~')/*127*/ ){
      continue;//skipping if the character isn't valid 
    }
    freq[c]++;// incrementing the value in the table that corresponds to the character (lets us count frequency)
    symbols++;// incrmenting the total number of letters within the file (statistics)

  }

  for (int i = 32; i < 128; i++){// this is our for loop to load our binary heap (32-127)
    if (freq[i] == 0) {// if the frequency for the character is 0, we can skip it, don't put it in our binary heap
      continue;
    }
    element* e = new element((unsigned char) i, freq[i]); 
    bh.insert(e);// inserting our element, frequency pair
    distinctSymbols++;//iterating on the number of unique letters (statistics)
   
  }

  file.close(); 

  return true;
  
}

bool HuffmanTree() {
  while(bh.size() != 1) {//ie, the tree is complete and only one node remains
    element* e = new element;// creating a new element
    e->left = bh.deleteMin();// putting the first node to the left
    e->right = bh.deleteMin();// second node to right
    e->frequency = e->right->frequency + e->left->frequency;// adding the frequencies so we can have "weights" for the interior nodes

    bh.insert(e);// putting the node in 
  }

  if (bh.size() == 1) {// this is a final check for error checking, don't have to return but I return for sanity
    return true; 
  } else {
    return false;
  }

}

void prefixCodes(element* e, string path_taken) {// method to 
  if ( e->left == NULL ) {//full binary tree so either both NULL, leaf or both full, interior
    if (e->character == ' ') {// for space we need to actually say "space" so taking care of that here
      cout << "space" << " " << path_taken << endl;
    } else {
      cout << e->character << " " << path_taken << endl;
    }
    key[e->character] = path_taken;// setting up our map with the paths for the said character
    
  } else {
    prefixCodes(e->left, path_taken + "0");
    prefixCodes(e->right, path_taken + "1");
  }

}

void encoder(string filename) {// iterates through the file and prints out paths to letters seperated by a space
  char g;
  ifstream file(filename);
  
  while (file.get(g)) {// loop to go through file
    string path = key[(unsigned char) g];
    cout << path << " ";// prints out the path
    finalBits+=path.length();// counter for telling how many bits are in the final file (statistics)

  }

  cout << endl;

  file.close(); 

}


void statistics() {// Just calculating statistics here
  cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
  cout << "There are " << distinctSymbols << " distinct symbols used." << endl;
  cout << "There were " << symbols*8 << " bits in the original file." << endl;
  cout << "There were " << finalBits << " bits in the compressed file." << endl;
  double cRatio = ((double) symbols*8)/ (double) finalBits; // casts to force the values to have decimals
  cout << "This gives a compression ratio of " << cRatio << "." << endl;
  double bPC = (double) finalBits/ (double) symbols; // casts to force the values to have decimals
  cout << "The cost of the Huffman tree is " << bPC << " bits per character." << endl;

}
