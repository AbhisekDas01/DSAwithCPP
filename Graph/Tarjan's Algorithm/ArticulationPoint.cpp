#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

//dfs function 
void DFS(int node , int parent , unordered_map<int , list<int>> &adj , vector<bool> &visited , 
            vector<int> &disc , vector<int> &low , vector<bool> &ap , int &timer)
{

    int child = 0; //to count number of childrens 
    visited[node] = true;

    //update timer 
    disc[node] = low[node] = timer++;

    //traverse all edges

    for(auto nbr : adj[node])
    {
        //if nbr is parent then skip 
        if(nbr == parent)
        {
            continue;
        }

        if(!visited[nbr])
        {
            child++;
            DFS(nbr , node , adj , visited , disc , low , ap , timer);

            //update the low value of currnode
            low[node] = min(low[node] , low[nbr]);

            if(low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = true;
            }
            
        }
        else
        {
            low[node] = min(low[node] , disc[nbr]); 
        }
        
    }

    //check for root node
    if(parent == -1 && child > 1)
    {
        ap[node] = true;
    }
}
int main()
{
    int n = 5;
    //create a edges list 
    vector<pair<int,int>> edges;

    edges.push_back({1,0});
    edges.push_back({0,4});
    edges.push_back({1,4});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({3,4});

    unordered_map<int , list<int>> adj;
    //create adj list 
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //initialisations of data for trajans algo 
    vector<bool> visited(n , false);
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    vector<bool> ap(n,false);
    int timer = 0;
    int parent = -1;

    //dfs calls
    for(int i = 0 ; i< n ;i++)
    {
        if(!visited[i])
        {
            DFS(i , parent , adj , visited , disc , low , ap , timer);
        }
    }


    cout << "Articulations points are : " ;
    for(int i = 0 ; i < n ;i++)
    {
        if(ap[i])
        {
            cout << i << " ";
        }
    }
    
    return 0;
}