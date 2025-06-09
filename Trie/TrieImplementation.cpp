#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminated; //to store the word termination
    
    TrieNode(char ch){

        this->data = ch;
        for(int i = 0 ; i< 26 ; i++){
            children[i] = NULL;
        }
        isTerminated = false;
    }
    
};


class Trie{

    private:
    TrieNode *root;


    //insert util function
    void insertUtil(TrieNode *root , string word){

        //base case
        if(word.length() == 0){
            root->isTerminated = true;
            cout << "Inserted word.." << endl;
            return;
        }

        //step->1 find the index to insert
        int idx = word[0] - 'a';

        TrieNode *child;

        //if char already present
        if(root->children[idx]){

            child = root->children[idx];
        }
        else{ //if not present
            // cout << word[0] << endl;
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child , word.substr(1));
    }

    bool searchUtil(TrieNode* root , string word){
        // base case 
        if(word.length() == 0){
            return root->isTerminated;
        }

        int idx = word[0] - 'a';

        TrieNode *child;

        if(root->children[idx]){
            child = root->children[idx];
        }else{
            return false;
        }

        return searchUtil(child , word.substr(1));
    }

    //delete function
    bool haveChildren(TrieNode *root){
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i])
                return true;
        }
        return false;
    }
    bool deleteUtil(TrieNode *root , string word){

        //base case
        if(word.length() == 0){
            root->isTerminated = false;

            //check is children exists
            return !haveChildren(root);
        }

        int idx = word[0] - 'a';

        TrieNode *child = root->children[idx];

        bool canDelete = deleteUtil(child , word.substr(1));

        if(canDelete){
            delete root->children[idx];
            root->children[idx] = NULL;
        }

        //check if root can be deleted
        if(root->isTerminated || haveChildren(root)){
            return false;
        }else  
            return true;
    }



    public:
    Trie(){
        root = new TrieNode('\0');
    }

    //insert word function
    void insertWord(string word){
        insertUtil(root , word);
    }

    //search function 
    bool searchWord(string word){
        
        if(searchUtil(root  , word)){
            cout << word << " is found" << endl;
            return true;
        }
        cout << word << " is not found!" << endl;
        return false;
    }

    void deleteWord(string word){

        if(searchWord(word)){

            deleteUtil(root , word);
            cout << "Deleted " << word << " ! " << endl;
        }
    }
};
int main(){
    
    Trie t;

    t.insertWord("abhisek");
    t.insertWord("abhipsa");
    t.insertWord("abhinav");
    t.searchWord("abhise");
    t.deleteWord("abhisek");
    t.searchWord("abhisek");
    return 0;
}