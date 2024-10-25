#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator for sorting edges by weight in ascending order
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

// Find function with path compression
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Union by rank function
void createSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    // Attach smaller rank tree under root of higher rank tree
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

// Kruskal’s Algorithm to find MST
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(n, 0);

    // Sort edges by weight in ascending order
    sort(edges.begin(), edges.end(), cmp);

    int minWeight = 0;

    // Iterate over all edges and construct MST
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        u = findParent(parent, u);
        v = findParent(parent, v);

        // If they are in different components, add the edge to MST
        if (u != v)
        {
            minWeight += w;
            createSet(parent, rank, u, v);
        }
    }
    return minWeight;
}

// Main function to test the MST function
int main()
{
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int result = minimumSpanningTree(edges, n);
    cout << "Weight of the minimum spanning tree: " << result << endl;

    return 0;
}
