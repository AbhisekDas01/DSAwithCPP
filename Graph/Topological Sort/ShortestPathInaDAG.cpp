#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <limits.h>
#include <vector>
using namespace std;

class Graph{
    
    public:
    unordered_map<int , list<pair<int , int> > > adj;

    public:
    void addEdge(int u , int v , int weight)
    {
        pair<int , int> p = make_pair(v,weight);

        adj[u].push_back(p);
    }

    void printGraph()
    {
        for(auto i : adj)
        {
            cout << i.first << " -> ";
            for(auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")," ;
            }
            cout << endl;
        }
    }

    //dfs traversal to find topo sort
    void DFS(unordered_map<int , bool> &visited , stack<int> &s , int node)
    {
        visited[node] = true;

        for(auto i : adj[node])
        {
            if(!visited[i.first])
            {
                DFS(visited , s , i.first);
            }
        }
        s.push(node);
    }

};
int main()
{
    int n = 6; // no of nodes
    Graph g;
        // add all edges to graph
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(3, 4,-1);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(4, 5, -2);

    //print graph

    cout << "Graph elements : " << endl;
    g.printGraph();

    //find topological sort
    unordered_map<int , bool> visited;
    stack<int> s;

    for(int i = 0 ; i < n ; i++)
    {
        if(!visited[i])
        {
            g.DFS(visited , s , i);
        }
    }

    int src = 1; //source node

    //create an distance array 
    vector<int> distance(n , INT_MAX);

    distance[src] = 0;

    while(!s.empty())
    {
        int currNode = s.top();
        s.pop();

        if(distance[currNode] != INT_MAX)
        {
            for(auto i : g.adj[currNode])
            {
                if(distance[currNode] + i.second < distance[i.first])
                {
                    distance[i.first] = distance[currNode] + i.second;
                }
            }
        }
    }

    //print distance array
    cout << "Distaces are : " << endl;
    for(auto i : distance)
    {
        cout << i << " ";
    }
    return 0;
}