#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// template is used to make the code generic for every datatype
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    // to add edge
    void addEdge(T u, T v, bool directed)
    {
        // direction = false //undirected
        // direction = true //directed

        // create the edge
        adjList[u].push_back(v);

        if (!directed)
        {
            adjList[v].push_back(u); // create an undirected edge
        }
    }

    // print the list
    void printList()
    {
        cout << "Graph data : " << endl;
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // take input of node pairs for edge cration
    void takeInput(int edge)
    {
        cout << "Enter " << edge << " pairs of nodes : " << endl;
        for (int i = 0; i < edge; i++)
        {
            T u, v;
            cin >> u >> v;
            addEdge(u , v , 1 ); //to make directed graph
        }
        cout << endl;
    }
};


int main()
{

    // crate a int type
    int node;
    cout << "Enter the number of nodes/vertices : ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    Graph<int> g;

    g.takeInput(edge);
    g.printList();
    return 0;
}