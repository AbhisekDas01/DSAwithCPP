#include <iostream>
using namespace std;

//tire node creation
class TrieNode
{
    public:
    char data; //to hold the character value 
    TrieNode *children[26]; //a tree with 26 child nodes to stores A-Z;

    bool isTerminal; //to check the string is ended or not 

    TrieNode(char ch)
    {
        data = ch;
        
        //mark all the child as null
        for(int i = 0 ; i < 26 ; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{
    private:
    TrieNode *root ;

    public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    private:
    //to insert letters one by one recursivly into the tire 
    void insertUtil(TrieNode *root , string word)
    {
        //base case 
        //if length of the sring becomes 0 then the insertion is complete
        if(word.length() == 0)
        {
            //mark the last node as terminal node
            root->isTerminal = true;
            cout << "Inserted..." << endl;
            return;
        }

        //step->1 find index of the child node
        int idx = word[0] - 'A';

        TrieNode *child; 

        //if character already present in the node then it will be not null
        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            //if children == NULL then craete new node
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        //recursive calls for next part 
        insertUtil(child , word.substr(1)); //pass the remaining string ;
    }

    //search fuction
    bool searchUtil(TrieNode *root , string word)
    {
        //base case
        //if we moved to the last node and its the terminal node then we found the word
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        //find index 
        int idx = word[0] - 'A';

        TrieNode *child ;
        //if the letter exists then the child will != NULL
        if(root->children[idx] != NULL)
        {
            //move to forward 
            child = root->children[idx];
        }
        else
        {
            //if is is null then element not present 
            return false;
        }

        //recursive calls 
        return searchUtil(child , word.substr(1));
    }


    //to check children
    bool haveChildren(TrieNode *root)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            if(root->children[i] != NULL)
            {
                return true;
            }
        }
        return false;
    }
    //delete function 
    bool deleteUtil(TrieNode *root , string word)
    {
        //base case 
        if(word.length() ==  0)
        {
            //we are at the last letter so mark if false for terminal node
            root->isTerminal = false;

            //check if it has any other child so it cant be deleted 
            return !haveChildren(root);
        }

        int idx = word[0] - 'A';
        TrieNode *child = root->children[idx];

        //find if the child  node can be deleted or not 
        bool canBeRemoved = deleteUtil(child , word.substr(1));

        //if it can be removed the delte it
        if(canBeRemoved)
        {
            delete root->children[idx];
            root->children[idx] = NULL;
        }

        //return if root can be deleted or not 
        //case -1 ->if root is a terminating node 
        //case -2 -> if root has any other child nodes 
        //then we cant delete root so return false
        if(root->isTerminal || haveChildren(root))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    public:
    void insertWord(string word)
    {
        insertUtil(root , word);
    }
    
    bool searchWord(string word)
    {
        return searchUtil(root , word);
    }

    void deleteWord(string word)
    {
        if(searchWord(word))
        {
            deleteUtil(root , word);
        }
    }
};

int main()
{
    Trie t;

    t.insertWord("ABHI");
    t.insertWord("ABHISEK");
    t.insertWord("ABH");

    if(t.searchWord("ABH"))
    {
        cout << "word found" << endl;
    }
    else
    {
        cout << "Not found " << endl;
    }
    t.deleteWord("ABH");
    cout << t.searchWord("ABH") << endl;
    cout << t.searchWord("ABHI");

    return 0;
}