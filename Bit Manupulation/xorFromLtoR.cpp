/*
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
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
int findXorFrom1toN(int n){
    // Find remainder when n is divided by 4 to determine pattern
    int mod = n % 4;

    // Apply the pattern based on remainder
    switch (mod) {
        case 1: return 1;        
        case 2: return n + 1;    
        case 3: return 0;       
        case 0: return n;     
    }
}

/**
 * Function to find XOR of all numbers in range [L, R]
 * 
 * Algorithm:
 * XOR from L to R = XOR(1 to R) ^ XOR(1 to L-1)
 * 
 * This works because:
 * XOR(1 to R) = 1 ^ 2 ^ 3 ^ ... ^ (L-1) ^ L ^ (L+1) ^ ... ^ R
 * XOR(1 to L-1) = 1 ^ 2 ^ 3 ^ ... ^ (L-1)
 * 
 * When we XOR these two results:
 * XOR(1 to R) ^ XOR(1 to L-1) = L ^ (L+1) ^ ... ^ R
 * 
 * The numbers from 1 to (L-1) cancel out due to XOR property: a ^ a = 0
 */
int findXorFromLtoR(int l, int r){

    // XOR from L to R = XOR(1 to R) ^ XOR(1 to L-1)
    return findXorFrom1toN(l - 1) ^ findXorFrom1toN(r);
    
}


int main(){
    int l, r;
    
    // Get input from user
    cout << "Enter the range [L, R]:" << endl;
    cout << "Enter L: ";
    cin >> l;
    cout << "Enter R: ";
    cin >> r;
    
    
    // Calculate XOR from L to R using optimized approach
    int result = findXorFromLtoR(l, r);
    
    // Display result
    cout << "XOR from " << l << " to " << r << " = " << result << endl;
    
    
    return 0;
}