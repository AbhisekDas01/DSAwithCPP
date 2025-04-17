#include <bits/stdc++.h>
using namespace std;

// Function implementing Dijkstra's algorithm
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // Step 1: Create adjacency list
    // Adjacency list stores each node with a list of pairs (edge weight, destination node)
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];  // Source node
        int v = vec[i][1];  // Destination node
        int d = vec[i][2];  // Weight of the edge

        // As the graph is undirected, add both directions
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    // Step 2: Create a set to store pairs of (distance, node) and a distance array initialized with INT_MAX
    set<pair<int, int>> s; // Stores pairs of (current distance, node)
    vector<int> dist(vertices, INT_MAX); // Distance array to store shortest distance from source to each node

    // Step 3: Initialize the source node with distance 0 and add it to the set
    s.insert({0, source});
    dist[source] = 0;

    // Step 4: Process the graph until the set is empty
    while (!s.empty()) {
        // Extract the node with the smallest distance
        pair<int, int> node = *s.begin();
        s.erase(s.begin()); // Remove the node from the set

        int currNode = node.second; // The node itself
        int currDist = node.first;  // The distance to this node

        // Step 5: Explore all neighbors of the current node
        for (auto neighbour : adj[currNode]) {
            int neighbourNode = neighbour.second;  // The neighboring node
            int edgeWeight = neighbour.first;      // The weight of the edge to the neighboring node

            // Step 6: If a shorter path is found
            if (currDist + edgeWeight < dist[neighbourNode]) {
                // Check if the neighbor node is already in the set
                auto it = s.find({dist[neighbourNode], neighbourNode});

                // If the neighbor is in the set, remove the outdated distance entry
                if (it != s.end()) {
                    s.erase(it);
                }

                // Update the shortest distance to the neighbor node
                dist[neighbourNode] = currDist + edgeWeight;

                // Insert the updated distance and node into the set
                s.insert({dist[neighbourNode], neighbourNode});
            }
        }
    }

    return dist; // Return the distance array with shortest distances from the source
}

int main() {
    // Example graph (edges) and number of vertices and edges
    int vertices = 5;  // Number of vertices in the graph
    int edges = 6;     // Number of edges in the graph
    int source = 0;    // Source node to calculate distances from

    // Example edges represented as {source, destination, weight}
    vector<vector<int>> vec = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 3, 5}, {2, 3, 1}
    };

    // Call the Dijkstra function to calculate the shortest distances
    vector<int> distances = dijkstra(vec, vertices, edges, source);

    // Output distances from the source to all other vertices
    cout << "Shortest distances from source node " << source << " to other nodes:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
