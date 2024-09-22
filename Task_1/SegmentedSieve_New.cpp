/**
 * @file    SegmentedSieve_New.cpp
 * @brief   Segmented Sieve to generate primes 
 *
 * @author  Azmain Inquaid Haque Turjo
 * @date    September 16, 2024
 *
 * @details This program implements the Segmented Sieve to generate all prime numbers
 *          up to a defined limit.
 */


#include <bits/stdc++.h>
using namespace std;

// Maximum limit for the sieve
const int MAX_LIMIT = 1e6;

// Array to store prime status (true if prime, false if not)
bool sieve[MAX_LIMIT + 1];

/**
 * @brief   Implements the Sieve of Eratosthenes to mark non-prime numbers.
 *
 * @details This function populates the `sieve` array where true indicates prime numbers and 
 *          false indicates non-prime numbers. It marks all multiples of a prime number starting 
 *          from its square as non-prime.
 */
void create_sieve() {
    // Initialize all numbers as prime
    fill(sieve, sieve + MAX_LIMIT + 1, true);
    
    // 0 and 1 are not prime numbers
    sieve[0] = sieve[1] = false;

    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= MAX_LIMIT; i++) {
        if (sieve[i]) {
            // Mark all multiples of i starting from i^2 as non-prime
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                sieve[j] = false;
            }
        }
    }
}

/**
 * @brief   Returns all prime numbers up to a given number.
 *
 * @details This function utilizes the `sieve` array to check for prime numbers 
 *          and stores all primes up to the number N in a vector.
 * 
 * @param   N The upper limit for prime numbers.
 * @return  A vector containing all prime numbers up to N.
 */
vector<int> get_primes(int N) {
    vector<int> primes;
    
    // Collect all numbers marked as prime in the sieve
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    // Optimize input/output performance
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute sieve for all numbers up to MAX_LIMIT
    create_sieve();

    int test_cases;
    cin >> test_cases;

    // Process each test case
    while (test_cases--) {
        int left_bound, right_bound;
        cin >> left_bound >> right_bound;

        // Get primes up to sqrt(right_bound) for segmented sieve
        vector<int> primes = get_primes(sqrt(right_bound) + 1);

        // Dummy array to mark prime numbers in the range [left_bound, right_bound]
        vector<bool> is_prime_in_range(right_bound - left_bound + 1, true);

        /**
         * @brief   Marks multiples of primes within the given range.
         *
         * @details For each prime in the `primes` vector, this marks all its multiples within the range 
         *          [left_bound, right_bound] as non-prime by updating the `is_prime_in_range` array.
         */
        for (int p : primes) {
            // Calculate the first multiple of prime p within the range
            int first_multiple = max(p * p, ((left_bound + p - 1) / p) * p);

            // Mark all multiples of p in the range [left_bound, right_bound] as non-prime
            for (int j = first_multiple; j <= right_bound; j += p) {
                is_prime_in_range[j - left_bound] = false;
            }
        }

        /**
         * @brief   Outputs all prime numbers in the given range.
         *
         * @details This iterates through the `is_prime_in_range` array and outputs all numbers marked as true,
         *          except for the number 1, as it's not a prime number.
         */
        for (int i = left_bound; i <= right_bound; i++) {
            if (is_prime_in_range[i - left_bound] && i != 1) {
                cout << i << '\n';
            }
        }

        // Separate test case outputs
        cout << '\n';
    }

    return 0;
}
 