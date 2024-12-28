// /Given an array ‘a’ of size ‘n’-1 with elements of range 1 to ‘n’. The array does not 
//contain any duplicates. Your task is to find the missing number.

#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number in the array
int missingNumber(vector<int>& a, int N) {
    int xor1 = 0;

    // XOR of all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        xor1 = xor1 ^ i;
    }

    int xor2 = 0;

    // XOR of all elements in the given array
    for (int i = 0; i < a.size(); i++) {
        xor2 = xor2 ^ a[i];
    }

    // The missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}

int main() {
    // Example usage
    vector<int> arr = {1, 2, 4, 5}; // Array with a missing number
    int N = 5; // Total numbers from 1 to N

    // Find and print the missing number
    int missing = missingNumber(arr, N);
    cout << "The missing number is: " << missing << endl;

    return 0;
}
