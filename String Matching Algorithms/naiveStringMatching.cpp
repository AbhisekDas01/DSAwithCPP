#include <iostream>
#include <string>
using namespace std;

void naiveStringMatcher(string& text , string& pattern){
    int n = text.length();
    int m = pattern.length();

    for(int i = 0 ; i <= n-m ; i++){
        int j;
        for(j = 0 ; j < m ; j++){

            if(text[i+j] != pattern[j])
                break;
        }


        if(j == m){
            cout << "Pattern matched at index " << i << " to " << i+m << endl;
        }
    }

}


int main()
{
    string text , pattern;

    cout << "Enter the text : ";
    cin >> text;
    cout << "Enter the pattern : ";
    cin >> pattern;

    naiveStringMatcher(text , pattern);

    return 0;
}