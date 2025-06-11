#include <iostream>
#include <string>
using namespace std;

int naiveStringMatching(string text , string pattern){

    int n = text.length();
    int m = pattern.length();

    if(n < m) return -1;

    for(int i = 0 ; i <= n-m ; i++){

        int j = 0;
        for( ; j < m ; j++){

            if(text[i+j] != pattern[j]){
                break;
            }
        }

        if(j == m) {
            return i;
        }
    }

    return -1;
}

int main(){
    
    string text , pattern;

    cout << "Enter the text : ";
    cin >> text;
    cout << "Enter the pattern : ";
    cin >> pattern;

    int index = naiveStringMatching(text , pattern);

    if(index == -1){
        cout << "pattern not matched" << endl;
        return 0;
    }
    cout << pattern << " matched from " << index  << " index";
    return 0;
}