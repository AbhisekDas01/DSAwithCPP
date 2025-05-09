#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct{

    int u , v , wt;
} Edges;

bool bellmanFord(Edges *edges , int vertex , int edge , int src , int *dist){
    //initialize distance as infinite
    for(int i = 0 ; i< vertex ; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // v-1 iterations to find shortest path
    for(int i = 0 ; i < vertex-1 ; i++){
        for(int j = 0 ; j < edge ; j++){

            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            //do the relaxation
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //the last the vth iteration to check for -ve cycles
    for(int i = 0 ; i < edge ; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            return true;
        }
    }

    return false;
}

int main(){
    
    int vertex , edge , src;

    printf("Enter the number of vertex & edges : ");
    scanf("%d%d" , &vertex , &edge);

    Edges * edges = (Edges *)malloc(edge * sizeof(Edges));

    printf("Enter the Edges (u , v , weight) : \n");
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d%d" , &edges[i].u , &edges[i].v , &edges[i].wt );
    }

    printf("Enter the src vertex : ");
    scanf("%d" , &src);

    int *dist = (int *)malloc(vertex*sizeof(int));

    bool negetiveCycle = bellmanFord(edges , vertex , edge , src , dist);


    if(negetiveCycle){
        printf("Negative weight cycle detected.");
    }else{
        
    //print shortest paths
        printf("vetex\tdistace form %d are:\n", src);
        for(int i = 0 ; i < vertex ; i++){
            printf("%d\t%d\n" , i , dist[i]);
        }
    }

    free(edges);
    free(dist);
    return 0;
}