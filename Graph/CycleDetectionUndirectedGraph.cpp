#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Function declarations
void BFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited,
         unordered_map<int, int>& parent, int node, string& ans);

string cycleDetection(vector<vector<int>>& edges, int n, int m);

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

// Existing BFS and cycleDetection functions go here

void BFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited,
         unordered_map<int, int>& parent, int node, string& ans) {
    queue<int> q;
    q.push(node);

    parent[node] = -1;
    visited[node] = true;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (auto neighbor : adj[currNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = currNode;
                q.push(neighbor);
            } else if (visited[neighbor] && parent[currNode] != neighbor) {
                ans = "Yes";
                return;
            }
        }
    }
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    string ans = "No";
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(adj, visited, parent, i, ans);
            if (ans == "Yes") {
                return ans;
            }
        }
    }

    return ans;
}
