#include <iostream>
using namespace std;
int main()
{
    int a , b;
    cout << "Enter two numbers : ";
    cin >> a >> b;


    while (b > 0)
    {
        int carry = (a&b) << 1;
        a = a^b;
        
        b = carry;
        
    }
    cout << "Sum : " << a ;

    return 0;
}