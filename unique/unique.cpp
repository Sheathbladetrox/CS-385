/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Andrew Chuah
 * Date        : September 16, 2019
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

/**
 * Checks if characters in a given string are lowercase letters.
 */
bool is_all_lowercase(const string &s) {
    int count = 0;
    for(unsigned int i = 0; i < s.length(); i++){
        if(isupper(s[i]) || !isalpha(s[i]))
            count++;
    }

    if(count == 0)
        return true;
    else
        return false;
}

/**
 * Checks to see that all letters in the string are unique, so no duplicates.
 * It uses one int for storage and uses bitwise and bitshift operators.
 */
bool all_unique_letters(const string &s) {
    if(s.length() == 0)
        return true;
    unsigned int storage = 0;
    for(unsigned int i = 0; i < s.length(); i++){
        int ascii_value = s[i] - 97;
        if((storage & (1 << ascii_value)) > 0)
            return false;
        storage |= (1 << ascii_value);
    }
    return true;
}

int main(int argc, char * const argv[]) {
    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
    }
    if(!is_all_lowercase(argv[1])){
        cerr << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }
    if(!all_unique_letters(argv[1])){
        cerr << "Duplicate letters found." << endl;
        return 1;
    }
    if(all_unique_letters(argv[1])){
        cout << "All letters are unique." << endl;
    }
}
