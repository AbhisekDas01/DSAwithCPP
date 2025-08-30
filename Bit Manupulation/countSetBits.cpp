#include <iostream>
using namespace std;

// Function to count the number of set bits (1s) in a number
// Method 1: Using division by 2 and remainder
int countSetBits(int num ){

    int count = 0;

    while (num > 0){
        
        count += num&1;  // Get the last bit
        num = num >> 1;           // Right shift by dividing by 2
        
    }

    return count;
}

// Alternative method using bit manipulation (more efficient)
int countSetBitsOptimized(int num) {
    int count = 0;
    
    while(num > 0) {
        count++;
        num = num & (num - 1);  // Clear the rightmost set bit
    }
    
    return count;
}

int main(){
    
    int num;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> num;
    
    // Count set bits using both methods
    int count1 = countSetBits(num);
    int count2 = countSetBitsOptimized(num);
    
    // Display results
    cout << "Number: " << num << endl;
    cout << "Number of set bits (1s): " << count1 << endl;
    cout << "Optimaized method: " << count2 << endl;
    
    
    return 0;
}