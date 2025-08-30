#include <iostream>
using namespace std;

// Function to set the nth bit (make it 1)
// Bit positions are counted from right starting at 0
int setNthBit(int num , int n ){
    return num | (1 << n);
}

int main(){
    
    int num, n;
    
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Enter the bit position to set (0-based from right): ";
    cin >> n;
    
    cout << "Original number: " << num << endl;
    
    int result = setNthBit(num, n);
    
    cout << "After setting bit " << n << ": " << result << endl;
    
    // Optional: Show binary representation
    cout << "Original binary: ";
    for(int i = 15; i >= 0; i--) {
        cout << ((num >> i) & 1);
        if(i % 4 == 0) cout << " ";
    }
    cout << endl;
    
    cout << "Modified binary: ";
    for(int i = 15; i >= 0; i--) {
        cout << ((result >> i) & 1);
        if(i % 4 == 0) cout << " ";
    }
    cout << endl;
    
    return 0;
}