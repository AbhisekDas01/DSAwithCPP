#include <iostream>
using namespace std;

// Function to toggle the nth bit (flip 0 to 1, or 1 to 0)
// Uses bitwise XOR with (1 << n)
// XOR properties: 0 ^ 1 = 1, 1 ^ 1 = 0
// Example: to toggle bit 2 in 1111, use 1111 ^ 0100 = 1011
int toggleNthBit(int num , int n){
    return num ^ (1 << n);  // XOR flips the bit at position n
}

int main(){

    int num , n;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the bit position to toggle (0-based from right): ";  
    cin >> n;

    // Toggle the nth bit using XOR operation
    int result = toggleNthBit(num , n);

    // Display results with proper descriptions
    cout << "Original number: " << num << endl;
    cout << "After toggling bit " << n << ": " << result << endl;

    // Show binary representation (16-bit for clarity)
    cout << "Original binary: ";
    for (int i = 15; i >= 0; i--){
        cout << ((num >> i) & 1);       // Extract each bit using right shift and AND
        if(i % 4 == 0) cout << " ";     // Add space every 4 bits for readability
    }
    cout << endl;

    cout << "Modified binary: ";
    for(int i = 15 ; i >= 0 ;i--){
        cout << ((result >> i) & 1);    // Show the result after bit toggle
        if(i % 4 == 0) cout << " ";     // Add space every 4 bits for readability
    }
    cout << endl;
    
    return 0;
}