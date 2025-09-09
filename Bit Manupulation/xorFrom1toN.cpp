/**
 * Given a number n, the task is to find the XOR from 1 to n.
Examples :

Input : n = 6
Output : 7
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7

Input : n = 7
Output : 0
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0
 */

#include <iostream>
using namespace std;

/**
 * Function to find XOR of all numbers from 1 to n using pattern observation
 * 
 * Pattern Analysis:
 * XOR from 1 to n follows a repeating pattern based on n % 4:
 * - If n % 4 == 1: XOR = 1
 * - If n % 4 == 2: XOR = n + 1  
 * - If n % 4 == 3: XOR = 0
 * - If n % 4 == 0: XOR = n
 * 
 * This pattern emerges because XOR is commutative and associative,
 * and every 4 consecutive numbers have a specific XOR pattern.
 */
int findXor(int n ){
    // Find remainder when n is divided by 4 to determine pattern
    int mod = n % 4;

    // Apply the pattern based on remainder
    switch (mod) {
    case 1:
        return 1;        // When n % 4 == 1, XOR from 1 to n = 1
    case 2:
        return n + 1;    // When n % 4 == 2, XOR from 1 to n = n + 1
    case 3: 
        return 0;        // When n % 4 == 3, XOR from 1 to n = 0
    case 0: 
        return n;        // When n % 4 == 0, XOR from 1 to n = n
    default:
        return 0;        // Default case (should never reach here)
    }
}

int main() {
    int n;
    
    // Get input from user
    cout << "Enter a number n to find XOR from 1 to n: ";
    cin >> n;
    
    
    // Calculate XOR using optimized approach
    int result = findXor(n);
    
    // Display result
    cout << "XOR from 1 to " << n << " = " << result << endl;
    
    return 0;
}