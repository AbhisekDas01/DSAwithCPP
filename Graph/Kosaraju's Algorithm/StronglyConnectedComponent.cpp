// step->1 find topo sort
// step->2 find transpose of graph
// step->3 do dfs on the transposed graph

#include <iostream>
#include <stack>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

// DFS function to find topological sort
void topoDFS(unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s, int node)
{
    visited[node] = true; // Mark the current node as visited

    // Visit all the adjacent nodes (neighbors) of the current node
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            topoDFS(adj, visited, s, nbr); // Recursive DFS call for unvisited neighbors
        }
    }

    // Push the node to the stack after all its neighbors are visited
    s.push(node);
}

// DFS function on the transposed graph to find SCCs
void sccDFS(unordered_map<int, list<int>> &revadj, vector<bool> &visited, int node)
{
    visited[node] = true; // Mark the current node as visited

    // Visit all the adjacent nodes in the transposed graph
    for (auto i : revadj[node])
    {
        if (!visited[i])
        {
            sccDFS(revadj, visited, i); // Recursive DFS call for unvisited neighbors in the transposed graph
        }
    }
}

// Function to find the number of strongly connected components (SCCs) in the graph
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Step 1: Create the adjacency list for the graph
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // Directed edge from u to v
    }

    // Step 2: Perform topological sort using DFS
    stack<int> s;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoDFS(adj, visited, s, i); // DFS call for each unvisited node
        }
    }

    // Step 3: Transpose the graph (reverse all edges)
    unordered_map<int, list<int>> revadj;
    for (auto i : adj)
    {
        visited[i.first] = false; //reset visited to false;
        for (auto j : i.second)
        {
            revadj[j].push_back(i.first); // Reverse the edge direction
        }
    }



    // Step 4: Process all nodes in topologically sorted order in the transposed graph
    int count = 0;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        // Perform DFS on the transposed graph for each unvisited node
        if (!visited[u])
        {
            count++; // Increment count for each SCC found
            sccDFS(revadj, visited, u);
        }
    }
    return count; // Return the number of strongly connected components
}

// Main function to test the stronglyConnectedComponents function
int main()
{
    int v = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 2}, {2, 1}, {1, 0}, {0, 3}, {3, 4}};

    // Calculate the number of strongly connected components
    int sccCount = stronglyConnectedComponents(v, edges);
    cout << "The number of strongly connected components is: " << sccCount << endl;

    return 0;
}
