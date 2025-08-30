#include <iostream>
using namespace std;

// Function to clear the last set bit (rightmost 1 bit)
// Uses bitwise AND with (num - 1)
// How it works: num-1 flips all bits after and including the last set bit
// Example: 12 (1100) & 11 (1011) = 8 (1000) - clears bit at position 2
int clearLastSetBit(int num){
    return num & (num - 1);  // AND with (num-1) clears the rightmost set bit
}

int main(){

    int num;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> num;

    // Clear the last set bit
    int result = clearLastSetBit(num);

    // Display results with proper descriptions
    cout << "Original number: " << num << endl;
    cout << "After clearing last set bit: " << result << endl;

    // Show binary representation (16-bit for clarity)
    cout << "Original binary: ";
    for (int i = 15; i >= 0; i--){
        cout << ((num >> i) & 1);       // Extract each bit using right shift and AND
        if(i % 4 == 0) cout << " ";     // Add space every 4 bits for readability
    }
    cout << endl;

    cout << "Modified binary: ";
    for(int i = 15 ; i >= 0 ;i--){
        cout << ((result >> i) & 1);    // Show the result after clearing last set bit
        if(i % 4 == 0) cout << " ";     // Add space every 4 bits for readability
    }
    cout << endl;
    
    
    return 0;
}