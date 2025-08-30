#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a , b , ans;
    cout <<"Enter the first Binary value : ";
    cin >> a;
    cout << "Enter the second binary value : ";
    cin >> b;
    int index1 = a.length() - 1 ;
    int index2 = b.length() -1;
    int carry = 0 ; // It will store the carry Bit;

    while (index1 >=  0 || index2 >= 0 || carry)
    {
        
        if(index1 >=0 )
            carry+=(a[index1--] - '0');
        if(index2>=0)
            carry+=(b[index2--]-'0');
        int digit = carry%2;//it will store the indivisual digits after addition 
        carry/=2;
        ans.push_back(digit + '0');
    }
    reverse(ans.begin(),ans.end());
    cout << a <<" + " << b <<" = " <<ans;
    return 0;
}