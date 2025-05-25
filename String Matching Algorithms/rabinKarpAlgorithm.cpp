#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void rabinKarpStringMatcher(string &text , string &pattern){

    int n = text.length();
    int m = pattern.length();
    int b = 256;
    int q = 101;
    int hash_p = 0;
    int hash_t = 0;

    //find hte hash value of the pattern and 1st substr
    for(int i = 0 ; i < m ; i++){
        hash_p = ( hash_p + (pattern[i]*(int)pow(b , m-i-1)))%q;
        hash_t = ( hash_t + (text[i]*(int)pow(b , m-i-1)))%q;
    }

    //slide over the pattern
    for(int i = 0 ; i <= n-m ; i++){
        //if the hash value matches 
        if(hash_t == hash_p){
            //then compare the chars
            int j;
            for(j = 0; j < m ; j++){

                if(text[i+j] != pattern[j]){
                    break;
                }
            }

            if(j == m){
                cout << "Pattern matched at index " << i << " to " << i+m << endl;
            }
        }

        //calculate the hash value for next window
        if(i < n-m){
            hash_t = ((hash_t - (text[i]*(int)pow(b, m-1)))*b + text[i+m])%q;
        }

    }
}
int main()
{
    string text , pattern;

    cout << "Enter the text : ";
    getline(cin , text);
    cout << "Enter the pattern : ";
    getline(cin , text);

    rabinKarpStringMatcher(text , pattern);
    return 0;
}