#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Function to find all distinct prime factors of a number
 * Returns a vector containing each prime factor only once
 * Time Complexity: O(sqrt(n))
 * Space Complexity: O(number of distinct prime factors)
 */
vector<int> primeFac(int n) {
        
        vector<int> ans;  // Store distinct prime factors
        
        // Check all numbers from 2 to sqrt(n) as potential factors
        for(int i = 2 ; i <= sqrt(n) ; i++){
            
            // If i divides n, then i is a prime factor
            if(n % i == 0){
                
                ans.push_back(i);  // Add this prime factor to result
                
                // Remove all occurrences of this factor from n
                // This ensures we don't count the same prime multiple times
                while(n%i == 0){
                    n /= i;  // Keep dividing n by i until i no longer divides n
                }
            }
        }
        
        // If n is still > 1, then remaining n is itself a prime factor
        // This handles cases where n has a prime factor greater than sqrt(original n)
        if(n != 1) ans.push_back(n);
        
        return ans;  // Return vector of distinct prime factors
        
    }

int main(){

    int n;

    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = primeFac(n);


    cout << "Prime factors of " << n << ": ";
    for(auto num : result)
        cout << num << " ";
    cout << endl;
    
    return 0;
}