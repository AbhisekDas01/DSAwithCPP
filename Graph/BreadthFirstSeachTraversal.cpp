#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

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

     // take input of node pairs for edge cration
    void takeInput(int edge , bool directed)
    {
        cout << "Enter " << edge << " pairs of nodes : " << endl;
        for (int i = 0; i < edge; i++)
        {
            T u, v;
            cin >> u >> v;
            addEdge(u , v , directed); //to make directed graph
        }
        cout << endl;
    }
};

vector<int> BFS(unordered_map<int , list<int>> &adj , int node)
{
    queue<int> q;
    unordered_map<int , bool> visited;

    vector<int> ans; //to store ans 
    visited[node] = true;

    q.push(node);

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        //store in the ans array 
        ans.push_back(currNode);

        //traverse the nodes linked with currNode
        for(auto i : adj[currNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
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


    bool directed;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> directed;

    Graph<int> g;

    g.takeInput(edge , directed);

    cout << "Enter any of the inserted node : ";
    int n;
    cin >> n;

    vector<int> ans = BFS(g.adjList , n); //this will not work for disconnected graph 

    cout << "BFS traversal : ";
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}