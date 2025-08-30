#include <iostream>
using namespace std;

// Function to check if nth bit is set (1) or not (0)
// Bit positions are counted from right starting at 0
bool findNthBitSet(int num, int n) {
    return num & (1 << n);
}

int main(){
    
    int num, n;
    
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Enter the bit position to check (0-based from right): ";
    cin >> n;
    
    // Check if nth bit is set
    if(findNthBitSet(num, n)) {
        cout << "Bit at position " << n << " is SET (1)" << endl;
    } else {
        cout << "Bit at position " << n << " is NOT SET (0)" << endl;
    }
    
    return 0;
}