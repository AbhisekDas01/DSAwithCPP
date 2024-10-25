#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

using namespace std;

// Function to perform Bellman-Ford algorithm
vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges)
{
    // Initialize distances with INT_MAX for unreachable nodes
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0; // Distance to source is 0

    // Relax edges up to (n-1) times
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0]; // Start vertex
            int v = edges[j][1]; // End vertex
            int w = edges[j][2]; // Weight of the edge

            // Update distance if a shorter path is found
            if (dist[u] < INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // If we can still relax an edge, return empty vector to indicate negative cycle
        if (dist[u] < INT_MAX && dist[u] + w < dist[v])
        {
            return {}; // Indicates that a negative weight cycle exists
        }
    }

    return dist; // Return the computed distances
}

int main()
{
     int n = 4;  // Number of vertices
    int m = 4;  // Number of edges
    int src = 1; // Source vertex
    // List of edges where each edge is represented as {u, v, w}
     vector<vector<int>> edges = {
        {1, 2, 4},  // Edge from 1 to 2 with weight 4
        {1, 3, 3},  // Edge from 1 to 3 with weight 3
        {2, 4, 7},  // Edge from 2 to 4 with weight 7
        {3, 4, -2}  // Edge from 3 to 4 with weight -2
    };

    // Compute shortest distances from the source vertex
    vector<int> distances = bellmanFord(n, m, src, edges);

    // Print distances from the source vertex
    cout << "Distances from source vertex " << src << ":" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (distances.empty() || distances[i] == INT_MAX)
        { // Check for unreachable vertices
            cout << "Vertex " << i << ": Unreachable" << endl;
        }
        else
        {
            cout << "Vertex " << i << ": " << distances[i] << endl; // Print distance
        }
    }

    return 0;
}
