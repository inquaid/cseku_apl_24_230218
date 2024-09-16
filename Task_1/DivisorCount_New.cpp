/**
 * @file    DivisorCount_New.cpp
 * @brief   Sieve of Eratosthenes to generate primes and divisor count of a given number.
 *
 * @author  Azmain Inquaid Haque Turjo
 * @date    September 16, 2024
 *
 * @details This program implements the Sieve of Eratosthenes to generate all prime numbers
 *          up to a defined limit. It also calculates and prints the distinct divisors of
 *          a given number and returns the total count of divisors.
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Limit for the sieve algorithm
#define MAX_LIMIT (1e6 + 6)

// Global variables for prime sieve and storing primes
bool isMarked[(long) MAX_LIMIT];
vector<int> primes;

/**
 * @brief   Implements the Sieve of Eratosthenes to mark non-prime numbers.
 *
 * @details This function populates the `isMarked` array where tre values indicate non-prim numbers.
 *          It also stores all prime numbers in the `primes` vector
 */

void seive() {
    int n = MAX_LIMIT;
    isMarked[0] = isMarked[1] = true; // 0 and 1 are not prime numbers

    // Marking non-prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (isMarked[i] == false) {
            for (int j = i * i; j <= n; j += i) {
                isMarked[j] = true;
            }
        }
    }

    // Collecting prime numbers
    for (int i = 0; i < n; i++) {
        if (isMarked[i] == false) {
            primes.push_back(i);
        }
    }
}

/**
 * @brief   Calculates the number of divisors of a given number.
 *
 * @param   n  The number whose divisors are to be found.
 *
 * @return  The total number of divisors of `n`.
 *
 * @details This function iterates through the prime numbers and finds the divisors of `n`.
 *          It stores each distinct divisor in a set and returns the total count of divisors.
 */

int divisor_count(int n) {
    set<int> divisors; // Set to store unique divisors
    int divisorCount = 1; // Initialize count with 1 for the number itself
    int primeSize = primes.size();

    // Iterating through primes to find divisors
    for (int i = 0; i < primeSize; i++) {
        while (n % primes[i] == 0) {
            divisors.insert(primes[i]); // Insert prime divisor
            divisors.insert(n / primes[i]); // Insert quotient as divisor
            divisorCount++; // Increase divisor count
            n /= primes[i]; // Divide n by the prime
        }
    }

    // Output the distinct divisors
    cout << "Divisors: ";
    for (auto divisor: divisors)
        cout << divisor << " ";
    cout << endl;

    return divisorCount * 2; // Multiply count by 2 for the full divisor count
}

/**
 * @brief   Main function to demostrate sieve and divisor counting
 */
int main() {
    seive(); // Run sieve to generate primes

    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "\n";
    cout << divisor_count(number) << endl;

    return 0;
}
