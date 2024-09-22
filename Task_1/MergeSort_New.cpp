/**
 * @file    MergeSort_New.cpp
 * @brief   Implementation of Merge Sort algorithm.
 *
 * @author  Azmain Inquaid Haque Turjo
 * @date    September 16, 2024
 *
 * @details  This module implements the Merge Sort algorithm using a divide-and-conquer approach.
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Alias for a vector of integers
using vi = vector<int>;

/**
 * @brief   Merges two sorted subarrays into a single sorted array.
 *
 * @details This function takes two sorted subarrays (`left_subarray` and `right_subarray`) 
 *          and merges them into the main array `array`. It compares elements from both 
 *          subarrays and inserts them in sorted order into `array`.
 * 
 * @param left_subarray The left half of the divided array.
 * @param right_subarray The right half of the divided array.
 * @param array The merged result of `left_subarray` and `right_subarray`.
 */
void merge(vi &left_subarray, vi &right_subarray, vi &array);

/**
 * @brief   Recursively divides the array into two halves for merge sort.
 *
 * @details This function recursively divides the array into two smaller subarrays 
 *          until the base case of 1 or 0 elements is reached. After dividing, it 
 *          merges the sorted subarrays back together.
 * 
 * @param array The array to be divided.
 */
void divide(vi &array);

/**
 * @brief   Performs merge sort on an array.
 *
 * @details This function calls `divide` to recursively divide the input array and
 *          then merges the sorted halves back together.
 * 
 * @param array The array to be sorted.
 */


void merge_sort(vi &array);

// Function to initiate the merge sort algorithm by dividing the array
void merge_sort(vi &array) {
    divide(array);
}

// Function to recursively divide the array into two halves
void divide(vi &array) {
    int len = array.size();
    
    // Base case: if the array has 1 or 0 elements, it's already sorted
    if (len <= 1)
        return;

    // Find the midpoint to divide the array
    int mid = len / 2;
    
    // Create left and right subarrays
    vi left_subarray(mid), right_subarray(len - mid);

    // Copy elements to the left and right subarrays
    copy(array.begin(), array.begin() + mid, left_subarray.begin());
    copy(array.begin() + mid, array.end(), right_subarray.begin());

    // Recursively divide the left and right subarrays
    divide(left_subarray);
    divide(right_subarray);

    // Merge the sorted left and right subarrays back into the original array
    merge(left_subarray, right_subarray, array);
}

// Function to merge two sorted subarrays into a single sorted array
void merge(vi &left_subarray, vi &right_subarray, vi &array) {
    int left_len = left_subarray.size();
    int right_len = right_subarray.size();

    // Indices to track the current position in the left, right, and merged arrays
    int i = 0, left_idx = 0, right_idx = 0;

    // Merge elements from both subarrays into the main array
    while (left_idx < left_len && right_idx < right_len) {
        if (left_subarray[left_idx] < right_subarray[right_idx]) {
            array[i] = left_subarray[left_idx];
            left_idx++;
        } else {
            array[i] = right_subarray[right_idx];
            right_idx++;
        }
        i++;
    }

    // Add any remaining elements from the left subarray
    while (left_idx < left_len) {
        array[i] = left_subarray[left_idx];
        i++;
        left_idx++;
    }

    // Add any remaining elements from the right subarray
    while (right_idx < right_len) {
        array[i] = right_subarray[right_idx];
        i++;
        right_idx++;
    }
}

int main() {
    // Input number of elements
    int n;
    cin >> n;

    // Create a vector to store the elements
    vi array(n);
    
    // Input the elements of the array
    for (auto &element : array)
        cin >> element;

    // Sort the array using merge sort
    merge_sort(array);

    // Output the sorted array
    for (auto element : array)
        cout << element << " ";
}
