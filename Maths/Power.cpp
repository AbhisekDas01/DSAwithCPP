#include <iostream>
using namespace std;
int Power(int n , int p ) 
{
    if(p==0)
        return 1;
    if(p == 1)
        return n;
    
    //recursion 
    int ans = Power(n,p/2); // this means a ^ b can be written as (a^b/2)^2

    // if p is odd
    if(p & 1)
        return ans * ans * n;
    else 
        return ans * ans ;
}
int main()
{
    int n , p ;
    cout << "Enter the number and power ";
    cin >> n >> p ;
    cout << "Power : "<< Power(n,p);
    return 0;
}