
//In this case, we are given the row number r and the column number c, and we need to find out the 
//element at position (r,c). 

#include <iostream>
using namespace std;
long long nCr(int n , int r)
{
    //find nCr most optimally
    long long res = 1;

    for(int i = 0 ; i < r ; i++)
    {
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}


int main()
{
    int row , col;

    cout << "Enter the row & col no you want to print : ";
    cin >> row >> col;

    //formula = (row-1)C(col-1)

    cout << nCr(row-1 , col-1);
    return 0;
}