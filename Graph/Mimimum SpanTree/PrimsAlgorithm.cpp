#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,  vector<pair<pair<int, int>, int>> &g){
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    key[1] = 0;

    for (int i = 1; i <= n; i++) {
        int mini = INT_MAX;
        int u = -1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }

        visited[u] = true;

        for (auto i : adj[u]) {
            int v = i.first;
            int w = i.second;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main() {
    int n = 5;
    int m = 6;

    vector<pair<pair<int, int>, int>> graph = {
        {{1, 2}, 2}, {{1, 4}, 6}, {{2, 3}, 3},
        {{2, 4}, 8}, {{3, 4}, 5}, {{3, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, graph);

    cout << "Edges in the MST:\n";
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
    }

    return 0;
}
