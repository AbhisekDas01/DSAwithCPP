long long nCr(int n , int r)
{
    //find nCr most optimally
    long long res = 1;

    for(int i = 0 ; i < r ; i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    //time complexity = O(r);
    return res;
}


#include <iostream>
using namespace std;
int main()
{
    
    int n , r;

    cout << "Enter n & r : ";
    cin >> n >> r;

    cout << nCr(n , r);

    return 0;
}