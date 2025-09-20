#include <iostream>
#include <vector>
using namespace std;

// Function to find and print all prime numbers up to n using Sieve of Eratosthenes
void printPrime(int n){

    // Create a boolean array to track prime numbers (initially all true)
    // Index represents the number, value represents if it's prime
    vector<bool> isPrime(n+1 , true);

    // Mark 0 and 1 as non-prime (if they exist in our range)
    if(n >= 0) isPrime[0] = false;
    if(n >= 1) isPrime[1] = false;

    // Sieve algorithm: start from 2 and mark multiples as non-prime
    for(int i = 2 ; i*i <= n ; i++){  // Fixed: i*1 should be i*i

        // If current number is still marked as prime
        if(isPrime[i]){

            // Mark all multiples of i (starting from i*i) as non-prime
            // Start from i*i because smaller multiples already marked by smaller primes
            for(int j = i*i ; j <= n ; j+=i){
                isPrime[j] = false;  // Mark as composite (not prime)
            }
        }
    }

    // Print all numbers that remain marked as prime
    for(int i = 2 ; i <= n ;i++){

        if(isPrime[i]){
            cout << i << " ";
        }
    }
}


int main(){

    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers between 1 -> " << n << ": ";
    printPrime(n);
    cout << endl;  // Add newline for better formatting
    
    return 0;
}