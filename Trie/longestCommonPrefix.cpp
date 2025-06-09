#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Trie node class
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};


// Trie class 
class Trie {

private:
    TrieNode* root;

    void insertUtil(TrieNode* root, string word) {

        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            // cout << "Inserted word.." << endl;
            return;
        }

        // step->1 find the index to insert
        int idx = word[0] - 'a';

        TrieNode* child;

        // if char already present
        if (root->children[idx]) {

            child = root->children[idx];
        } else { // if not present
            // cout << word[0] << endl;
            child = new TrieNode(word[0]);
            root->children[idx] = child;
            root->childCount++;
        }

        insertUtil(child, word.substr(1));
    }

    string prefixUtil(TrieNode* root, string word) {

        // base case
        if (root->childCount == 0 || root->childCount > 1 ||
            word.length() == 0 || root->isTerminal) {
            return "";
        }

        int idx = word[0] - 'a';

        TrieNode* child;

        if (root->children[idx]) {

            child = root->children[idx];
            return child->data + prefixUtil(child, word.substr(1));
        }

        return "";
    }

public:
    Trie() { root = new TrieNode('\0'); }

    void insertWord(string word) { insertUtil(root, word); }

    string findPrefix(string word) { return prefixUtil(root, word); }
};


string longestCommonPrefix(vector<string>& strs) {

        Trie t;
        for (auto it : strs) {
            t.insertWord(it);
        }

        return t.findPrefix(strs[0]);
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