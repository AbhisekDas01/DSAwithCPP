#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

// DFS function to detect a cycle in an undirected graph
bool isCyclicDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int node, int parent) {
    visited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Recursive call for unvisited neighbor
            if (isCyclicDFS(adj, visited, neighbor, node)) {
                return true;
            }
        }
        // If the adjacent node is visited and it's not the parent, a cycle exists
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph using DFS
string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    // Create the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    // Check each node for cycles
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(adj, visited, i, -1)) {
                return "Yes";
            }
        }
    }

    return "No";
}

// Main function to take user input and check for cycles
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (each as two space-separated integers representing two nodes):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Call the cycle detection function
    string result = cycleDetection(edges, n, m);

    // Output the result
    cout << "Cycle detection result: " << result << endl;

    return 0;
}
