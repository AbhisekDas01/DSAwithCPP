//hashmap implementation with closed addressing 
#include <iostream>
#include <vector>
#include <list> //to use linked list
#include <algorithm>

using namespace std;

class hashMap
{
    private:
    vector<list<int>> hashTable; //vector of linkedlists to implement closed addressing
    int buckets;

    public:
    hashMap(int size)
    {
        buckets = size;
        hashTable.resize(buckets);
    }

    //to find hash code
    int hashCode(int key)
    {
        return key%buckets; //division method
    }

    //to push the key in hash table
    void addKey(int key)
    {
        //step ->1 find index
        int index = hashCode(key);
        hashTable[index].push_back(key); // insert the key in last node of the linked list 
    }

    //search function 
    list<int> :: iterator searchKey(int key)
    {
        int index = hashCode(key);
        auto it =  find(hashTable[index].begin(),hashTable[index].end() , key);
        return it;
    }

    void deleteKey(int key)
    {
        //find index
        int index = hashCode(key);

        //check if the key present or not 
        if(searchKey(key) != hashTable[index].end())
        {
            hashTable[index].erase(searchKey(key));
            cout << "Deleted " << key << endl;
        }
        else
        {
            cout << "Key not found!" << endl;
        }
    }
};
int main()
{
    
    hashMap h(10);

    h.addKey(682);
    h.addKey(761);
    h.addKey(494);
    h.addKey(567);
    h.addKey(869);
    h.addKey(634);
    h.addKey(794);

    h.deleteKey(794);
    h.deleteKey(794);

    h.deleteKey(567);


    return 0;
}