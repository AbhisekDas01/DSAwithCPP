#include <iostream>
using namespace std;
void PrintDigit(int n , string arr[])
{
    //base case 
    if (n==0)
    {
        return ;
    }

    int digit = n %10;
    n/=10;

    PrintDigit(n,arr);

    //printing in stack way 
    cout << arr[digit]<<" ";
    
}
int main()
{
    string arr[10] = {"Zero" , "One" ,"Two", "Three","Four","Five","Six","Seven","Eight","Nine"};
    int n ; 
    cout <<"Enter a number : "; 
    cin >> n;
    PrintDigit(n,arr);
    return 0;
}