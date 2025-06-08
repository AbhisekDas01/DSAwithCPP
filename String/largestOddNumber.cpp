/**
 * You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 
 */

#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
        
    string ans = "";
    int n = num.size();
    int length = -1;
    for(int i = n-1 ; i >= 0 ; i--){

        int digit = num[i] - '0';

        if(digit &1 ){
            length = i;
            break;
        }
    }

    for(int i = 0 ; i <= length ; i++){

        ans.push_back(num[i]);
    }

    return ans;

}

int main(){
    string number;

    cout << "Enter a number : ";
    cin >> number;

    string odd = largestOddNumber(number);

    cout << "Largest odd number : " << odd;
    return 0;
}