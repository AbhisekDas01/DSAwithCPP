//Kahn's algorithm 
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Step 2: Create indegree array
    vector<int> indegree(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // Step 3: Push all nodes with 0 indegree to the queue
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 4: Perform BFS and build topological order
    vector<int> ans;
    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);

        // Visit all neighbors and reduce their indegree
        for (auto neighbour : adj[currNode]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main() {
    // Number of vertices (v) and edges (e)
    int v, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> v >> e;

    // Input edge list
    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Call topological sort function
    vector<int> result = topologicalSort(edges, v, e);

    // Check if topological sort is possible (result size should match number of vertices)
    if (result.size() == v) {
        cout << "Topological Sort: ";
        for (auto node : result) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Graph has a cycle, topological sort not possible." << endl;
    }

    return 0;
}
