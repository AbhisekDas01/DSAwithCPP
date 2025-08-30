#include <iostream>
using namespace std;

// Function to check if a number is a power of 2
// Uses bit manipulation: n & (n-1) == 0
// Powers of 2 have only one bit set: 1, 2, 4, 8, 16, etc.
// Example: 8 (1000) & 7 (0111) = 0, so 8 is a power of 2
bool checkPowerof2(int num){
    return (num > 0) && ((num & (num-1)) == 0);  // Added num > 0 check
}

int main(){
    
    int num;
    cout << "Enter a number: ";
    cin >> num;  // Fixed: 'cint' should be 'cin'

    // Check if the number is a power of 2
    if(checkPowerof2(num)) {
        cout << num << " is a power of 2" << endl;
    } else {
        cout << num << " is NOT a power of 2" << endl;
    }
    
    return 0;
}