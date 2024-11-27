//this algorithm is used to find gcd(a,b)
//gcd(a,b) = gcd(a-b, b) ~ gcd(a%b , b)

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