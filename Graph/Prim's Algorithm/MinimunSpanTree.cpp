#include <bits/stdc++.h>
using namespace std;

// Function to calculate Prim's Minimum Spanning Tree (MST)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, 
                                        vector<pair<pair<int, int>, int>> &g)
{
    // Create an adjacency list to represent the graph
    unordered_map<int, list<pair<int, int>>> adj;

    // Fill the adjacency list from the edge list
    for (int i = 0; i < m; i++) {
        int u = g[i].first.first; // Start node of the edge
        int v = g[i].first.second; // End node of the edge
        int w = g[i].second; // Weight of the edge

        adj[u].push_back({v, w}); // Add edge from u to v with weight w
        adj[v].push_back({u, w}); // Add edge from v to u with weight w (undirected graph)
    }

    // Vectors to store key values (weights), parent nodes, and visited nodes
    vector<int> key(n + 1, INT_MAX); // Key values (initialized to infinity)
    vector<int> parent(n + 1, -1);   // Parent array to store the MST structure
    vector<bool> visited(n + 1, false); // Visited array to track selected nodes

    // Start from node 1 (assuming nodes are 1-indexed)
    key[1] = 0; // Set the key of the starting node to 0 (this node will be picked first)

    // Prim's algorithm to build the MST
    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX; // Initialize the minimum key value
        int u = -1; // Initialize the node to be picked

        // Find the node with the minimum key value that hasn't been visited
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        // Mark the node as visited
        visited[u] = true;

        // Update the key values of adjacent vertices
        for (auto i : adj[u]) {
            int v = i.first;  // Neighboring vertex
            int w = i.second; // Weight of the edge

            // Update key if the edge weight is smaller than the current key value
            if (!visited[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u; // Update the parent to track the MST structure
            }
        }
    }

    // Prepare the result as a vector of edges (u, v) with their weights
    vector<pair<pair<int, int>, int>> ans;

    // Loop through nodes starting from 2 (since node 1 is the root)
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]}); // Add the edge (parent[i], i) with its weight
    }

    return ans; // Return the MST edges
}

int main() {
    int n = 5;  // Number of nodes
    int m = 6;  // Number of edges

    // List of edges in the format { {u, v}, weight }
    vector<pair<pair<int, int>, int>> graph = {
        {{1, 2}, 2}, {{1, 4}, 6}, {{2, 3}, 3},
        {{2, 4}, 8}, {{3, 4}, 5}, {{3, 5}, 7}
    };

    // Call Prim's MST function
    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, graph);

    // Print the edges of the MST
    cout << "Edges in the MST:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
