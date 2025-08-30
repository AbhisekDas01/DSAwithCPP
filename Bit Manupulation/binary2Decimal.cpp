#include <iostream>
#include <string>

using namespace std;

// Function to convert binary string to decimal number
long long findDecimal(string &binary){

    int n = binary.length();  // Get length of binary string

    long long decimal = 0;  // Initialize decimal result

    long long power = 1;  // Start with 2^0 = 1 (rightmost bit)

    // Process binary string from right to left
    for(int i = n-1 ; i >= 0 ; i--){

        // Convert char to int and multiply by current power of 2
        decimal += (binary[i] - '0') * power;
        
        // Move to next power of 2 (multiply by 2)
        power *= 2;
    }

    return decimal;
}

int main(){
    
    string binary;
    
    cout << "Enter a binary number: ";
    cin >> binary;
    
    // Validate binary string
    bool isValid = true;
    for(char c : binary) {
        if(c != '0' && c != '1') {
            isValid = false;
            break;
        }
    }
    
    if(!isValid) {
        cout << "Invalid binary number! Please enter only 0s and 1s." << endl;
    } else {
        long long decimal = findDecimal(binary);
        cout << "Decimal representation of " << binary << " is: " << decimal << endl;
    }
    
    return 0;
}