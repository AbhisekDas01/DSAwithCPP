#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// DFS function to detect a cycle in a directed graph
bool isCyclicDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited,
                    unordered_map<int, bool>& DFSvisited, int node) {
    visited[node] = true;
    DFSvisited[node] = true;

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Recursive call to check neighbors
            if (isCyclicDFS(adj, visited, DFSvisited, neighbor)) {
                return true;
            }
        }
        // If a node in the current DFS path is found, it means there's a cycle
        else if (DFSvisited[neighbor]) {
            return true;
        }
    }

    // Mark the node as no longer being in the DFS path
    DFSvisited[node] = false;
    return false;
}

// Function to detect cycle in a directed graph
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);  // Directed edge from u to v
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;

    // Check for a cycle in each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(adj, visited, DFSvisited, i)) {
                return 1;  // Cycle found
            }
        }
    }

    return 0;  // No cycle found
}

// Main function to take user input and check for cycles
int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int>> edges(m);
    
    cout << "Enter the edges (each as two space-separated integers representing a directed edge):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    // Call the cycle detection function
    int result = detectCycleInDirectedGraph(n, edges);

    // Output the result
    if (result == 1) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
