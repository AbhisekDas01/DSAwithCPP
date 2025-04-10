#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{

    int u , v , weight;
} Edges;

//compare function of qsort
int compare(const void *a , const void *b){
    Edges *e1 = (Edges *)a;
    Edges *e2 = (Edges *)b;

    return e1->weight - e2->weight;
}


void createSet(int *parent, int *size , int vertex){

    for(int i = 0 ;i  < vertex ; i++){
        size[i] = 1;
        parent[i] = i;
    }
}

int findParent(int *parent , int u){
    if(parent[u] == u) return u;

    return parent[u] = findParent(parent , parent[u]);
}

void Union(int u , int v , int *parent , int *size){

    u = findParent(parent , u);
    v = findParent(parent , v);

    if(size[u] > size[v]){
        parent[v] = u;
        size[u] += size[v];
    }
    else{
        parent[u] = v;
        size[v]+=size[u];
    }
}

int KruskalsMST(Edges * edges , int *parent , int *size , int vertex , int edge){

    int weight = 0;
    createSet(parent, size , vertex );

    qsort(edges , edge , sizeof(Edges) , compare);

    printf("Edges are : \n");
    for(int i = 0 ; i < edge ; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].weight;

        if(findParent(parent , u) != findParent(parent , v)){

            Union(u , v , parent , size);
            weight += wt;

            printf("%d %d = %d\n" , u , v , wt);


        }
    }


    return weight;

}

int main()
{
    int vertex , edge;
    printf("Enter the number of vertex & edges : ");
    scanf("%d%d" , &vertex , &edge);

    Edges * edges = (Edges *)malloc(edge * sizeof(Edges));

    printf("Enter the Edges (u , v , weight) : \n");
    for (int i = 0; i < edge; i++)
    {
        scanf("%d%d%d" , &edges[i].u , &edges[i].v , &edges[i].weight );
    }

    int *parent = (int *)malloc((vertex+1) * sizeof(int) );
    int *size = (int *)malloc((vertex+1) * sizeof(int) );

    int weight = KruskalsMST(edges , parent , size , vertex , edge);

    printf("Weight of MST : %d" , weight);

    free(size);
    free(parent);
    free(edges);
    return 0;
}