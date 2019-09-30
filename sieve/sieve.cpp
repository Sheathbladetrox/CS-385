/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Andrew Chuah
 * Date        : September 9, 2019
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

// Displays the prime numbers in a nice and uniform way, almost as if it was written in a Word doc.
void PrimesSieve::display_primes() const {
    const int max_prime_width = num_digits(max_prime_);
    const int primes_per_row = 80 / (max_prime_width + 1);
    // If there's only one line of primes:
    if (num_primes_ <= primes_per_row){
        for (int i = 0; i <= limit_; i++){
			if (is_prime_[i]){
				if(i != max_prime_)
					cout << i << " ";
				else
					cout << i << endl;
            }
        }			
	}
    // If there's more than one line of primes:
	else{
		for (int i = 0, count = 1; i <= limit_; i++){
			if (is_prime_[i] == true){
				if(count != primes_per_row){
					if (i != max_prime_){
						cout << setw(max_prime_width) << i << " ";
						count++;
					}
					else{
						cout << setw(max_prime_width) << i;
                        count++;
					}
				}
                else{
					cout << setw(max_prime_width) << i << endl;
					count = 1;
				}
			}
		}
	}
}

// Takes count of the number of primes based on the boolean value from the sieve.
int PrimesSieve::count_num_primes() const {
    int count = num_primes_;

    for(int i = 2; i <= limit_; i++){
        if(is_prime_[i]){
            count++;
        }
    }
    return count;
}

/**
 * Creates a sieve for prime numbers.
 * Makes the sieve initially true, and then filters out the primes, leaving everything else false.
 */
void PrimesSieve::sieve() {
    for(int i = 2; i <= limit_; i++){
        is_prime_[i] = true;
    }

    for(int i = 2; i <= sqrt(limit_); i++){
        if(is_prime_[i]){
            for(int j = i*i; j <= limit_; j+=i){
                is_prime_[j] = false;
            }
        }
    }

    num_primes_ = count_num_primes();

    // This loop finds the largest prime and breaks the loop.
    for(int k = limit_; k >= 2; k--){
        if(is_prime_[k]){
            max_prime_ = k;
            break;
        }
    }
}

// Returns the number of digits of a number in the sieve.
int PrimesSieve::num_digits(int num) {
    int digits = 0;
    while(num != 0){
        num /= 10;
        digits++;
    }
    return digits;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    cout << endl;
    PrimesSieve sieve1(limit);
    cout << "Number of primes found: " << sieve1.num_primes() << endl;
    cout << "Primes up to " << limit << ":" << endl;
    sieve1.display_primes();

    return 0;
}
