#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

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

    // take input of node pairs for edge creation
    void takeInput(int edge, bool directed)
    {
        cout << "Enter " << edge << " pairs of nodes : " << endl;
        for (int i = 0; i < edge; i++)
        {
            T u, v;
            cin >> u >> v;
            addEdge(u, v, directed); // to make directed graph
        }
        cout << endl;
    }
};

// DFS function
void DFS(unordered_map<int, list<int>> &adjList, vector<int> &ans, int node, unordered_map<int, bool> &visited)
{
    // push the node
    ans.push_back(node);
    visited[node] = true;

    // call for next part
    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            DFS(adjList, ans, i, visited);
        }
    }
}

int main()
{
    // create a int type
    int node;
    cout << "Enter the number of nodes/vertices : ";
    cin >> node;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    bool directed;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    Graph<int> g;

    g.takeInput(edge, directed);

    unordered_map<int, bool> visited;
    vector<int> ans;

    // Perform DFS for each node in case of disconnected graph
    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            DFS(g.adjList, ans, i, visited);
        }
    }

    // Output DFS traversal
    cout << "DFS traversal : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
