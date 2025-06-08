/**
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 */


#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int min(int a , int b){

    return (a < b)? a : b;
}

string longestCommonPrefix(vector<string>& strs) {
        
    string prefix = "";

    int prefixLen = INT_MAX;

    for(auto it : strs){

        prefixLen = min(prefixLen , it.length());
    }

    int index = 0;

    while(index < prefixLen){

        char digit = strs[0][index];
        bool common = true;
        for(auto str : strs){

            if(str[index] != digit){
                common = false;
                break;
            }
        }

        if(!common) break;
        index++;
        prefix.push_back(digit);
    
    }

    return prefix;
}
int main(){
    
    vector<string> strs;
    int n;
    cout << "Enter number of strings : ";
    cin >> n;
    cout << "Enter "<< n << " strings  : ";

    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        strs.push_back(str);
    }

    string prefix = longestCommonPrefix(strs);

    cout << "longest common prefix : " << prefix;
    return 0;
}