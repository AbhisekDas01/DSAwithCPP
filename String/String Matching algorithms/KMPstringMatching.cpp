#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Creates the Longest Proper Prefix which is also Suffix (LPS) array
 * LPS[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]
 */
vector<int> longestPrefixSuffix(string &s) {
    // Initialize LPS array with zeros
    int n = s.length();
    vector<int> lps(n, 0);
    
    // Two pointers: prefix and suffix
    int pre = 0, suf = 1;
    
    while(suf < n) {
        // Case 1: Characters match
        if(s[pre] == s[suf]) {
            lps[suf] = pre + 1;
            pre++; 
            suf++;
        }
        // Case 2: Characters don't match
        else {
            // If pre is at start, no prefix matches
            if(pre == 0) {
                lps[suf] = 0;
                suf++;
            }
            // Try matching with shorter prefix
            else {
                pre = lps[pre-1];
            }
        }
    }
    return lps;
}

/**
 * KMP Pattern Searching Algorithm
 * Returns vector of all starting indices where pattern is found in text
 */
vector<int> KMPstringMatcher(string text, string pattern) {
    // Get lengths and LPS array
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = longestPrefixSuffix(pattern);
    vector<int> ans;
    
    // Base case: pattern longer than text
    if(n < m) return ans;
    
    // Two pointers for text and pattern
    int first = 0;  // text pointer
    int second = 0; // pattern pointer
    
    while(first < n) {
        // Case 1: Characters match
        if(text[first] == pattern[second]) {
            first++;
            second++;
        }
        // Case 2: Characters don't match
        else {
            if(second == 0) {
                first++;
            } else {
                second = lps[second-1];
            }
        }
        
        // Pattern found
        if(second == m) {
            ans.push_back(first - m);
            second = lps[second-1]; // Look for more occurrences
        }
    }
    return ans;
}

int main() {
    string text, pattern;
    
    // Get input
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    
    // Find all occurrences using KMP
    vector<int> matches = KMPstringMatcher(text, pattern);
    
    // Print results
    if(matches.empty()) {
        cout << "Pattern not found in text" << endl;
    } else {
        cout << "Pattern found at positions: ";
        for(int pos : matches) {
            cout << pos << " ";
        }
        cout << endl;
    }
    
    return 0;
}