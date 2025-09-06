

#include <iostream>
#include <climits>
using namespace std;

/**
 * Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
 */

int divide(int dividend , int divisor){
    // Handle edge case: dividend is 0
    if(dividend == 0) return 0;
    
    // Determine the sign of the result
    bool sign = false;
    if(dividend < 0 && divisor > 0) sign = true;  // Negative result
    if(dividend > 0 && divisor < 0) sign = true;  // Negative result

    // Initialize quotient and convert to positive long long to avoid overflow
    long long quotient = 0;
    long long n = abs((long long)(dividend));  // Absolute value of dividend
    long long d = abs((long long)(divisor));   // Absolute value of divisor

    // Use bit manipulation to perform division
    while(n >= d){
        int cnt = 0;
        // Find the largest power of 2 such that d * (2^cnt) <= n
        while(n >= (d << (cnt + 1))) cnt++;

        // Subtract the largest possible multiple and add to quotient
        n -= (d << cnt);        // n = n - (d * 2^cnt)
        quotient += (1L << cnt); // quotient = quotient + 2^cnt
    }

    // Handle overflow cases
    if(sign && quotient > (1L << 31)) return INT_MIN;        // Overflow to negative
    if(!sign && quotient > (1L << 31) - 1) return INT_MAX;   // Overflow to positive

    // Return result with appropriate sign
    return sign? (-1 * quotient) : quotient;
}

int main() {
    int dividend, divisor;
    
    // Get input from user
    cout << "Enter dividend: ";
    cin >> dividend;
    
    cout << "Enter divisor: ";
    cin >> divisor;
    
    // Check for division by zero
    if(divisor == 0) {
        cout << "Error: Division by zero is not allowed!" << endl;
        return 1;
    }
    
    // Perform division and display result
    int result = divide(dividend, divisor);
    cout << dividend << " / " << divisor << " = " << result << endl;
    
    return 0;
}