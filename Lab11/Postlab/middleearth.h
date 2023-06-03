// Sidhardh Burre, ssb3vk@virginia.edu, 4/28/2021, middleearth.h
#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

/**
 * @file middleearth.h
 *
 * @brief The header file for the middleEarth.cpp file.
 *
 * @author Sidhardh Burre
 * Contact: ssb3vk@virginia.edu
 * @date 4/28/2021
 */
class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    void print();
    void printTable();
    float getDistance(const string& city1, const string& city2);
    vector<string> getItinerary(unsigned int length);

private:
    int num_city_names, xsize, ysize; /*!< Int values detailing the number of cities and the dimensions of the graph */
    unordered_map<string, float> xpos, ypos; /*!< Maps to detail the x/y positions of the cities */
    vector<string> cities; /*!< A vector string of the subset of cities to be used */
    unordered_map<string, unordered_map<string, float>> distances; /*!< A map of distances betwen cities */

    mt19937 gen; /*!< Mersenne-Twister random number engine */
};

#endif
