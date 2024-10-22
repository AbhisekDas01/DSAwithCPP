#include <bits/stdc++.h>
using namespace std;

// Helper function to perform DFS and push nodes to the stack in topological order
void TopoSort(unordered_map<int, list<int>>& adj, stack<int>& ts, unordered_map<int, bool>& visited, int node) {
    visited[node] = true;

    // Recur for all the vertices adjacent to this vertex
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            TopoSort(adj, ts, visited, neighbour);
        }
    }

    // Push the current node to the stack after visiting all its neighbors
    ts.push(node);
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>>& edges, int numVertices, int numEdges) {
    // Stack to store the topological sort
    stack<int> ts;

    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Create a visited map to track visited vertices
    unordered_map<int, bool> visited;

    // Perform DFS on all unvisited nodes
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            TopoSort(adj, ts, visited, i);
        }
    }

    // Pop elements from stack to get the topological order
    vector<int> ans;
    while (!ts.empty()) {
        ans.push_back(ts.top());
        ts.pop();
    }

    return ans;
}

// Main function to take input and output the topological sort
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> edges(numEdges, vector<int>(2));

    cout << "Enter the edges (as two space-separated integers representing a directed edge from u to v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Call the topological sort function
    vector<int> result = topologicalSort(edges, numVertices, numEdges);

    // Output the topological order
    cout << "Topological sort of the graph: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
