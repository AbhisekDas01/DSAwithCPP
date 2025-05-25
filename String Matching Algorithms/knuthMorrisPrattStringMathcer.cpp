#include <iostream>
#include <string>
#include <vector>
using namespace std;


void createLps(string &pattern, vector<int> &lps) {
    int m = pattern.length();
    int k = -1;  // Should start from -1, not 0
    lps[0] = -1; // Initialize first element to -1

    for(int i = 1; i < m; i++) {
        while (k >= 0 && pattern[k+1] != pattern[i]) {
            k = lps[k];
        }
        
        if(pattern[k+1] == pattern[i]) // Fix comparison
            k++;
        
        lps[i] = k;
    }
}

void KMPstringMatcher(string &text, string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);

    createLps(pattern, lps);

    int q = -1;
    for(int i = 0; i < n; i++) {
        while (q >= 0 && pattern[q+1] != text[i]) {
            q = lps[q];
        }
        
        if(q == -1 || pattern[q+1] == text[i])
            q++;
            
        if(q == m-1) {  // Match found
            cout << "Pattern found at index " << i-m+1 << endl;
            q = lps[q];
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

    KMPstringMatcher(text , pattern);
    return 0;
}