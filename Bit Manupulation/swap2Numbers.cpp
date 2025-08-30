#include <iostream>
using namespace std;

// Function to swap two numbers using XOR bitwise operation
// XOR properties: a ^ a = 0, a ^ 0 = a, XOR is commutative and associative
void swap(int &a , int &b){
    a = a ^ b;  // a now contains a^b
    b = a ^ b;  // b = (a^b) ^ b = a^b^b = a^0 = a (original value of a)
    a = a ^ b;  // a = (a^b) ^ a = a^b^a = b^0 = b (original value of b)
}

int main(){

    int a, b;

    cout << "Enter two numbers to swap: ";
    cin >> a >> b;
    
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    
    // Call swap function
    swap(a, b);
    
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    
    return 0;
}