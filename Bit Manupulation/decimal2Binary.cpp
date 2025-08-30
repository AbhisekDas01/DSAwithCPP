#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string findBinary(int n){

    string binary;

    while(n > 0){

        int rem = n%2;
        n/=2;

        binary.push_back(rem + '0');  // Convert int to char
    }

    reverse(binary.begin() , binary.end());

    return binary;
}

int main(){

    int decimal;
    
    cout << "Enter a decimal number: ";
    cin >> decimal;
    
    if(decimal == 0) {
        cout << "Binary representation: 0" << endl;
    } else if(decimal < 0) {
        cout << "Please enter a positive number" << endl;
    } else {
        string binary = findBinary(decimal);
        cout << "Binary representation of " << decimal << " is: " << binary << endl;
    }
    
    return 0;
}