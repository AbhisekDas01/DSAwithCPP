#include <iostream>
#include <unordered_map> //unordered map is used to implement hash map in cpp
using namespace std;
int main()
{
    //syntax 
    //unordered_map<key_datatype , value_datatype > name;

    unordered_map<char , int> m;

    //inserting elements is map
    //method 1
    pair<char , int> p = make_pair('a',6);
    m.insert(p);

    //method 2
    pair<char ,int> p1('b',5);
    m.insert(p1);

    //method 3
    m['c'] = 7; //if no entry is present for c then it will create a new entry else it will update the previos entry 


    //to print the size of the map
    cout << "size : " << m.size() << endl;

    //search 
    cout << m['a'] << endl;
    //or
    cout << m.at('a') <<endl;

    //if the key not exists 
    // cout << m.at('d') << endl; (it will throw an error because no entry exists )
    //but
    cout << m['d'] << endl; //it will create a new entry for d as 0 then show 0
    cout << m.at('d') << endl; //now it will show zero 0


    //Count the number of elements present in an unordered_map with a given key
    cout << m.count('a') << endl;

    //erase function to delete from map
    // m.erase('a');


    //to access map elements 
    cout << "1st method : " << endl;
    for(auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    //using itrator
    cout << "method 2 " << endl;
    unordered_map<char , int > :: iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    
    return 0;
}