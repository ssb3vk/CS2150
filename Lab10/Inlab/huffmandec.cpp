//Sidhardh Burre, ssb3vk@virginia.edu, 4/21/2021, huffmandec.cpp
// Some parts of this code come from the slides

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "element.h"

using namespace std;

element* root; //our global variable that points to our root node

void huffmanTreeMaker(element *node, char value, string prefix_code); //creates the huffman tree
void decoder(element *node, string allbits); // converts the coded values into letters for humans


// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    root = new element; //initializing our global pointer for our root

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;

	// do something with the prefix code

	// need to cast character(string) into a char
	huffmanTreeMaker(root, character[0], prefix); // Here is our function

	//cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    
    decoder(root, allbits); // our decoder function
    
    // close the file before exiting
    file.close();

    delete root;
    
}


void huffmanTreeMaker(element* node, char value, string prefix_code) {
  if (prefix_code == "") {// base case
    node->character = value;
    return;

  } else {
    if ( prefix_code[0] == '0' ) {// go left
      if ( node->left == NULL ) {
	element* e = new element();
	node->left = e;
      }

      huffmanTreeMaker(node->left, value, prefix_code.substr(1)); //interstingly enough, the susbstr method can just cut ur string from index 1 (0 indexed) to the end
	
    } else {
      if ( node->right == NULL ) {
	element* e = new element();
	node->right = e;
      }

      huffmanTreeMaker(node->right, value, prefix_code.substr(1));

    }

  }

}

void decoder(element* node, string allbits) {
  //cout << allbits << "length: " << allbits.length() << endl; 
  if (allbits.length() == 0) {// the base case, we are done with our string
    cout << node->character << endl;
    return;

  }

  if (node->left == NULL) {// checking if we are at a root node
    cout << node->character;
    decoder(root, allbits); //continuing on

  } else {
    if ( allbits[0] == '0' ) {// go left
      decoder(node->left, allbits.substr(1)); 
	
    } else {
      decoder(node->right, allbits.substr(1));

    }

  }

}
