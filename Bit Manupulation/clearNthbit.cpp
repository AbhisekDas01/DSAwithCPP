#include <iostream>
using namespace std;

// Function to clear the nth bit (make it 0)
// Uses bitwise AND with complement of (1 << n)
// Example: to clear bit 2 in 1111, use 1111 & ~(0100) = 1111 & 1011 = 1011
int clearNthBit(int num , int n){
    return num & (~(1 << n));
}

int main(){

    int num , n;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the bit position to clear (0-based from right): ";
    cin >> n;

    // Clear the nth bit
    int result = clearNthBit(num , n);

    // Display results
    cout << "Original number: " << num << endl;
    cout << "After clearing bit " << n << ": " << result << endl; 

    // Show binary representation (16-bit for clarity)
    cout << "Original binary: ";
    for (int i = 15; i >= 0; i--){
        cout << ((num >> i) & 1);
        if(i % 4 == 0) cout << " ";  // Add space every 4 bits for readability
    }
    cout << endl;

    cout << "Modified binary: ";
    for(int i = 15 ; i >= 0 ;i--){
        cout << ((result >> i) & 1); 
        if(i % 4 == 0) cout << " "; 
    }
    cout << endl;
    
    return 0;
}