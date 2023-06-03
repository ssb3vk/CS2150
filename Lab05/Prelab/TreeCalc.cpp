//Sidhardh Burre, ssb3vk@virginia.edu, 3/19/2021, TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
// Don't actually think we need to do anything here
TreeCalc::TreeCalc() {  }

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  while ( !expressionStack.empty() ) {
    cleanTree( expressionStack.top() );
    expressionStack.pop();
  }
  
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if ( (tree->left != NULL) && (tree->right != NULL) ) {
    cleanTree( tree->left );
    cleanTree( tree->right );
    delete tree;
    return;
    
  } else {
    tree->right = NULL;
    tree->left = NULL;
    delete tree; 
    return;
    
  } 
    
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if ( isdigit(val[0]) ) {
    TreeNode * number = new TreeNode( val ); 
    expressionStack.push( number );
    return;
    
  } else if ( isdigit(val[1]) ) {
    TreeNode * negator = new TreeNode( val );
    expressionStack.push( negator ); 
    return;
    
  } else {
    TreeNode * operand = new TreeNode( val );
    operand->right = expressionStack.top();
    expressionStack.pop();
    operand->left = expressionStack.top();
    expressionStack.pop();
        
    expressionStack.push( operand );
    
    return;
    
  }
  
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  //print the tree in prefix format

  if ( (tree->right != NULL) && (tree->left != NULL) ) {
    cout << tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);

  } else {
    cout << tree->value << " ";

  }

}
 

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if ( (tree->right != NULL) && (tree->left != NULL) ){
    if ( !(isdigit(tree->value[0])) ){
      cout << "(";

    }
    printInfix(tree->left);
    cout << " " << tree->value[0] << " ";
    printInfix(tree->right);
    if( !(isdigit(tree->value[0])) ){
      cout << ")";

    }

  } else {
    cout << tree->value;

  }
  
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if ( (tree->right != NULL) && (tree->left != NULL) ) {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value << " ";
  } else {
    cout << tree->value << " ";

  }
  
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  if ( (tree->right == NULL) && (tree->left == NULL) ){
    return stoi(tree->value);
  } else {
    if ( tree->value[0] == '+' ) {
      return calculate(tree->left) + calculate(tree->right);

    } else if ( tree->value[0] == '-' ) {
      return calculate(tree->left) - calculate(tree->right);

    } else if ( tree->value[0] == '*' ) {
      return calculate(tree->left) * calculate(tree->right);

    } else if ( tree->value[0] == '/' ) {
      return calculate(tree->left) / calculate(tree->right);

    }
    
  }

  return 0;
  
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  // call private calculate method here
  return calculate( expressionStack.top() );
  
}
