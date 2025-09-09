//this algorithm is used to find gcd(a,b)
//gcd(a,b) = gcd(a-b, b) ~ gcd(a%b , b)

/**
 * EUCLIDEAN ALGORITHM
 * 
 * This algorithm is used to find the Greatest Common Divisor (GCD) of two numbers.
 * 
 * Mathematical Principle:
 * - gcd(a, b) = gcd(a - b, b) when a > b
 * - More efficiently: gcd(a, b) = gcd(a % b, b) when a > b
 * - The algorithm continues until one of the numbers becomes 0
 * - When one number becomes 0, the other number is the GCD
 * 
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(1)
 * 
 * Example:
 * gcd(48, 18):
 * 48 % 18 = 12, so gcd(48, 18) = gcd(12, 18)
 * 18 % 12 = 6,  so gcd(12, 18) = gcd(12, 6)
 * 12 % 6 = 0,   so gcd(12, 6) = gcd(0, 6) = 6
 */


#include <iostream>
using namespace std;

int GCD(int a , int b)
{
    while(a > 0 && b > 0)
    {
        if(a>b)
        {
            a = a%b;
        }
        else
        {
            b = b%a;
        }
    }

    return (a == 0)? b : a;
}

int main()
{
    int a , b ;
    cout << "Enter two numbers : ";
    cin >> a >> b;

    int gcd = GCD(a , b);
    long lcm = (long)(a*b)/gcd;

    cout << "GCD : " << gcd << endl;
    cout << "LCM : " << lcm << endl;
    return 0;
}