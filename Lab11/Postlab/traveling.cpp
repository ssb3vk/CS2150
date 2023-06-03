// Sidhardh Burre, ssb3vk@virginia.edu, 4/28/2021, traveling.cpp

/**
 * @file traveling.cpp
 *
 * @brief File that computes traveling salesperson for MiddleEarth
 *
 * @author Sidhardh Burre
 * Contact: ssb3vk@virginia.edu
 * @date 4/28/2021
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief The main method, does heavy lifting before passing to functions
 *
 * @return Zero, the default value for the main method. 
 * @param argc The number of arguments
 * @param argv The string arguments (world height, width, num cities, seed, cities to visit) 
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    string start = dests[0];

    sort(dests.begin() + 1, dests.end()); // sorting dests, for the next_permutation function, the first one don't matter

    /**
    for (string s: dests) {
      cout << s << endl;
    }
    */

    if ( dests.size() == 1 ) { // no permutations, can just output the path
      cout << "Minimum path has distance " << computeDistance(me, start, dests) << ": ";
      printRoute(start, dests);
    } else {
      vector<string> output;
      float minDist = numeric_limits<float>::max(); // set to constant value ( no function ). Ehh no point, its like 38 zeros.  

      
      do {
	float dist = computeDistance(me, start, dests);
	if ( dist < minDist ) {
	  minDist = dist; 
	  output = dests;
	}
	
      } while ( next_permutation(dests.begin()+1, dests.end()) );
      
      cout << "Minimum path has distance " << minDist << ": "; 
      printRoute(start, output);
      
    }

    //me.printTable(); 
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/**
 * @brief Computes the full distance of each cycle. 
 *
 * Using a middle earth object as well as the inputs for the starting node 
 * and destination nodes, this method will compute the full distance of the 
 * cycle. This cycle starts at the 'start' parameter, goes to each city IN ORDER,
 * and back to the 'start' parameter. 
 *
 * @return The value of the path length. 
 * @param me The MiddleEarth object that was created. 
 * @param start The start node within the path. 
 * @param dests The destinations within the path to travel to. 
 */
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
  float dist = me.getDistance(start, dests[0]) + me.getDistance(start, dests[dests.size()-1]); 
  for (int i = 1; i < dests.size(); i++) {// iterates through vector getting the distances
    dist += me.getDistance(dests[i-1], dests[i]);
  }
  
  return dist;
  
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * @brief Will print the complete route traveresed. 
 *
 * This method will print the entire route, starting and ending at the 
 * 'start' parameter. The output will be formatted as such: 
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 *
 * @param start The start node on the path. 
 * @param dests A vector of strings containing the destinations traversed. 
 */
void printRoute(const string& start, const vector<string>& dests) {
  for (string s : dests) {
    cout << s << " -> ";
  }
  cout << start << endl;
    
}
