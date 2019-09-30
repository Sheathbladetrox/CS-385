/*******************************************************************************
 * Name    : stairclimber.cpp
 * Author  : Andrew Chuah
 * Date    : September 24, 2019
 * Description : Lists the number of ways to climb n stairs.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * This creates an object with an input of the number of stairs.
 * It will return empty if the number of stairs is less than 0.
 * It will return all the ways to climb the number of stairs in the form of a vector of vectors of integers.
 */
vector<vector<int>> get_ways(int num_stairs){
    vector<vector<int>> ways;
    vector<int> empty;

    if(num_stairs <= 0)
        ways.push_back(empty);
    else{
        vector<vector<int>> result;
        for(int i = 1; i <= 3; i++){
            if(num_stairs >= i){
                result = get_ways(num_stairs - i);
                for(unsigned int j = 0; j < result.size(); j++){
                    result.at(j).push_back(i);
                    ways.push_back(result.at(j));
                }
            }
            sort(ways.begin(), ways.end());
        }
    }
    return ways;
}

/**
 * This function displays all the ways to climb a number of stairs with a certain format.
 */
void display_ways(const vector<vector<int>> &ways){
    for(unsigned int i = 0; i < ways.size(); i++){
        if(ways.size() > 9){
            if(i < 9)
                cout << " " << i + 1 << ". " << "[";
            else
                cout << i + 1 << ". " << "["; 
        }
        else
            cout << i + 1 << ". " << "[";
        
        for(unsigned int j = 0; j < ways[i].size(); j++){
            if(j != ways[i].size() - 1)
                cout << ways[i][j] << ", ";
            else
                cout << ways[i][j];
        }
        cout << "]" << endl;
    }
}

int main(int argc, char * const argv[]){
    int x;
    istringstream iss;

    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
        return 1;
    }

    iss.str(argv[1]);

    if(!(iss >> x)){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
    if(x < 1){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }

    vector<vector<int>> stairs = get_ways(atoi(argv[1]));

    if(x == 1)
        cout << "1 way to climb 1 stair." << endl;
    else
        cout << stairs.size() << " ways to climb " << argv[1] << " stairs." << endl;
    
    display_ways(stairs);
}