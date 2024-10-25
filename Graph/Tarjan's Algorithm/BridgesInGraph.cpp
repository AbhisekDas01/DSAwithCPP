// Tarjan's Algorithm to Find Bridges in an Undirected Graph

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm> // for min function
using namespace std;

// Helper function for DFS traversal and bridge-finding
void DFS(unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<int> &disc,
         vector<int> &low, int node, int parent, int &timer, vector<vector<int>> &result)
{

    // Mark the current node as visited and initialize discovery and low times
    visited[node] = true;
    disc[node] = low[node] = timer++;

    // Explore all adjacent nodes
    for (auto it : adj[node])
    {
        // Skip the parent node to prevent cycling back
        if (it == parent)
        {
            continue;
        }

        if (!visited[it])
        {
            // Recursive DFS for unvisited nodes
            DFS(adj, visited, disc, low, it, node, timer, result);

            // Update low value of current node based on child
            low[node] = min(low[node], low[it]);

            // Condition for identifying a bridge
            if (disc[node] < low[it])
            {
                vector<int> ans = {node, it};
                result.push_back(ans);
            }
        }
        else
        {
            // Update low[node] for back edges
            low[node] = min(low[node], disc[it]);
        }
    }
}

// Main function to find all bridges in the graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> result; // Store bridges

    // Create adjacency list from edges
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize discovery and low arrays and visited array
    int timer = 0;
    vector<bool> visited(v, false);
    vector<int> disc(v, -1); // Discovery time of each node
    vector<int> low(v, -1);  // Lowest discovery time reachable from each node

    // Run DFS from each unvisited node
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(adj, visited, disc, low, i, -1, timer, result);
        }
    }

    return result;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Find bridges using Tarjan's algorithm
    vector<vector<int>> bridges = findBridges(edges, v, e);

    // Print all identified bridges
    cout << "Bridges in the graph:\n";
    for (const auto &bridge : bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
