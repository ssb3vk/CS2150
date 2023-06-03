// Sidhardh Burre, ssb3vk@virginia.edu, 4/28/2021, topological.cpp

/**
 * @file topological.cpp
 * 
 * @brief Performs a topological sort on a text file-based input
 *
 * @author Sidhardh Burre
 * Contact: ssb3vk@virginia.edu
 * @date 4/28/2021
 */

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <map>
#include <queue>

using namespace std; 

/**
 * @brief Performs a topological sort on an inputted graph
 *
 * Uses an adjacencyMatrix, a map (for ordering purposes) string->int, a numberOfNodes input, and a string array (for ordering 
 * purposes (int->string) to topologically sort the input graph detailed in the adjacency matrix. 
 *
 * @param adjacencyMatrix An adjacency matrix detailing directional edges between nodes
 * @param mapContainingSortedNodes A map that, through its sorted property, can be used to assign an numeric value to each string node.
 * @param numberOfNodes The number of nodes within the graph. 
 * @param nodeDictionary A string array that is used to assign a string node to an int. 
 */
void topSort (int** adjacencyMatrix, map<string, int> mapContainingSortedNodes, int numberOfNodes, string* nodeDictionary); 


/**
 * @brief Manages the I/O as well as the array creation before calling the 
 * topological sort function. 
 *
 * Goes through the function to count the number of unique nodes
 * creates an n by n array pointer made of arrays to pointers of said size.
 * Also maps each string value from input to a numeric value via a unordered set. 
 *
 * @return Zero, default value for a main method. 
 * @param argc The number of arguments. 
 * @param argv The string arguments (will be a filename). 
 * 
 */

int main(int argc, char**argv) {
  ifstream file(argv[1], ifstream::binary); //creating a file object with the passed in filename
  map<string, int> nodeAddress; // key map to store nodes, essentially used as a set. Better cause its sorted automatically

  if (argc != 2) {// ensure the correct number of inputs are supplied
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  
  if (!file.is_open()) {// error checking for reading through the file
    cout << "Unable to open ' " << argv[1] << " ' for reading" << endl;
    exit(2);
  }

  while(true) {// loop to iterate through file and populate our set (unordered map) as well as for a count of the number of elements (map.size()) and the dist array
    string s1, s2;
    file >> s1;
    file >> s2;

    if (s1 == "0" && s2 == "0") {// this is how we know to quit the loop
      break;
    }

    // using the map as the dist array, if needed
    nodeAddress[s1] = -1;// adding the string (node name) to the map with a dist of -1
    nodeAddress[s2] = -1;// adding the other string to the map dist of -1

  }

  int nodeCount = nodeAddress.size(); 
  int **adjMatrix = new int*[nodeCount];// initializing our array of pointers for the adj Matrix
  for ( int i = 0; i < nodeCount; i++ ) {// initializing the adj matrix for all 0 values
    adjMatrix[i] = new int[nodeCount];
    for ( int j = 0; j < nodeCount; j++ ) {
      adjMatrix[i][j] = 0;
    }

  }

  string nodeDictionary[nodeCount];// an array that we can use to assign int values to our string-based nodes  
  
  file.seekg(0);// resetting where we are in the file 

  while(true) {// loop to iterate through file and set up our adjacency matrix
    string s1, s2;
    file >> s1;
    file >> s2;

    if (s1 == "0" && s2 == "0") {
      break;
    }

    // This distance stuff was found at stackoverflow.com/questions/17863079/get-index-of-element-in-c-map
    //cout << distance(nodeAddress.begin(), nodeAddress.find(s1)) << ": " << s1 << endl;
    //cout << distance(nodeAddress.begin(), nodeAddress.find(s2)) << ": " << s2 << endl; 

    // setting up our nodeDictionary
    nodeDictionary[distance(nodeAddress.begin(), nodeAddress.find(s1))] = s1;
    nodeDictionary[distance(nodeAddress.begin(), nodeAddress.find(s2))] = s2; 
    
    // mark as 1 to indicate a directional pointer in that direction
    adjMatrix[distance(nodeAddress.begin(), nodeAddress.find(s1))][distance(nodeAddress.begin(), nodeAddress.find(s2))] = 1; 
    
  }

  file.close();
  // closing the file before I forget to

  /*
  map< string, int>::iterator it; 
  for (it = nodeAddress.begin(); it != nodeAddress.end(); it++) {
    cout << it->first << endl;
  }
  
  for ( int i = 0; i < nodeCount; i++ ) {
    cout << nodeDictionary[i] << endl;

  }

  for ( int i = 0; i < nodeCount; i++ ) {// printing out the adjacency matrix
    for ( int j = 0; j < nodeCount; j++ ) {
      cout << adjMatrix[i][j]; 
    }

    cout << i << endl; 
  }
  */
  
  topSort(adjMatrix, nodeAddress, nodeCount, nodeDictionary); 

  for (int i = 0; i < nodeCount; i++ ) {// memory management, deleting our 2D array
    delete [] adjMatrix[i];
  }
  delete [] adjMatrix;
  
  return 0;

}


void topSort(int** adjacencyMatrix, map<string, int> nodeAddress, int numberOfNodes, string* nodeDictionary) {
  queue<string> q; // initializing the queue
  int counter = 0;
  string v, w;
  
  for( int i = 0; i < numberOfNodes; i++ ) {
    int inDegree = 0; 
    for ( int j = 0; j < numberOfNodes; j++ ) {
      inDegree+=adjacencyMatrix[j][i]; 
      
    }
    nodeAddress[nodeDictionary[i]] = inDegree; //setting up the node/indegree association.
    
    if ( inDegree == 0 ) {
      q.push(nodeDictionary[i]); // enquing if 0 indegree
      
    }
    
  }

  /*
  map< string, int>::iterator it; 
  for (it = nodeAddress.begin(); it != nodeAddress.end(); it++) {// indegree holder
    cout << it->first << ": " << it->second << endl;
  }

  for ( int i = 0; i < numberOfNodes; i++ ) {// node Dictionary print out
    cout << nodeDictionary[i] << endl;

  }
  */
  
  while (!q.empty()) {
    v = q.front(); // get vertex of indegree 0
    q.pop(); 
    counter++; 
    cout << v << " ";

    // int i = distance(nodeAddress.begin(), nodeAddress.find(v)); // uncomment to use first if statement (more efficient)

    for( int j = 0; j < numberOfNodes; j++ ) {
      /*
      if (adjacencyMatrix[i][j] == 1 && --nodeAddress[nodeDictionary[j]] == 0) {
	// cout << v << " pushing " << nodeDictionary[j] << endl; 
	q.push(nodeDictionary[j]);
      }
      */
      
      if (adjacencyMatrix[ distance(nodeAddress.begin(), nodeAddress.find(v))][j] == 1){
	if (--nodeAddress[nodeDictionary[j]] == 0){
	  q.push(nodeDictionary[j]);
	  
	}
	
      }
      
      
    }

  }
  
  if (counter != numberOfNodes) {
    cout << "A cycle was found" << endl;
  }

  cout << endl; // for spacing reasons, makes the console look ugly otherwise
  
}
