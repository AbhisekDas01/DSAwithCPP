// Graph implementation using adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

// template is used to make the code generic for every datatype
template <typename T>
class Graph
{
public:
    

    // to add edge
    void addEdge(vector<vector<bool>> &adj ,T u, T v, bool directed)
    {
           // Check for valid indices
        if(u >= adj.size() || v >= adj.size() || u < 0 || v < 0) {
        cout << "Invalid node index: " << u << " or " << v << endl;
        cout << "Try other pair : ";
        return;
    }

        // direction = false //undirected
        // direction = true //directed

        // create the edge
        adj[u][v] = true;

        if(!directed)
        {
            adj[v][u] = true; //if its undirected
        }
    }

    // print the list
    void printList(const vector<vector<bool>> &adj)
    {
        cout << "Graph Data : " << endl;
        for (int i = 0; i < adj.size(); i++)
        {
            bool isPrinted = false;
            for(int j = 0 ; j < adj.size() ; j++)
            {
                if(adj[i][j])
                {
                    if(!isPrinted)
                    {
                        cout << i << " -> ";
                        isPrinted = true;
                    }
                    cout << j << " ";
                }
            } 
            cout << endl;  
        }
        
    }

    // take input of node pairs for edge cration
    void takeInput(vector<vector<bool>> &adj ,int edge , bool directed)
    {
        cout << "Enter " << edge << " pairs of nodes : " << endl;
        for (int i = 0; i < edge; i++)
        {
            T u, v;
            cin >> u >> v;
            addEdge(adj , u , v , directed); //to make directed graph
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

    //create edge vector
    vector<vector<bool>> adj(node , vector<bool>(node , 0));

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;


    bool directed;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    Graph<int> g;

    g.takeInput(adj , edge , directed);
    g.printList(adj);
    return 0;
}