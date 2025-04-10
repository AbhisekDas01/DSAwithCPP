#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct Node
{
    int data , wt;
    struct Node *next;
} Node;

typedef struct heap{
    int wt , node , parent;
} heap;

heap minHeap[MAX];
int parent[MAX];      
int heapSize = 0;

void swap(int i , int j){
    heap temp = minHeap[i];
    minHeap[i] = minHeap[j];
    minHeap[j] = temp;
}

void minHeapify(int i){
    int small = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < heapSize && minHeap[left].wt < minHeap[small].wt)
        small = left;
    if(right < heapSize && minHeap[right].wt < minHeap[small].wt)
        small = right;

    if(small != i){
        swap(i , small);
        minHeapify(small);
    }
}


Node* createNode(int data, int wt) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->wt = wt;
    newNode->next = NULL;
    return newNode;
}

void insert(int wt , int node , int parent){

    int i = heapSize++;
    minHeap[i].wt = wt;
    minHeap[i].node = node;
    minHeap[i].parent = parent;

    while(i > 0){

        int parentIdx = (i-1)/2;

        if(minHeap[parentIdx].wt > minHeap[i].wt){
            swap(parentIdx , i);
            i = parentIdx;
        }
        else   
            break;
    }

}

heap extractMin() {
    heap root = minHeap[0];
    minHeap[0] = minHeap[--heapSize];
    minHeapify(0);
    return root;
}


void addEdge(Node *adjList[] , int u , int v , int wt){

    //u->v
    Node *newNode = createNode(v , wt);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    //undirected graph v->u
    newNode = createNode(u ,wt);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}


int primsMST(Node *adjList[] , int vertex , int edge){

    int visited[MAX] = {0};

    insert(0 , 0 , -1);
    // visited[0] = 1;
    int weight = 0;

    while(heapSize > 0){
        heap it = extractMin();

        int node = it.node;
        int prt = it.parent;
        int wt = it.wt;

        if(visited[node] == 1) continue;

        visited[node] = 1;
        parent[node] = prt;

        Node *temp = adjList[node];
        weight+=wt;

        while(temp){

            if(!visited[temp->data]){
                insert(temp->wt , temp->data , node);
            }

            temp = temp->next;

        }
    }

    return weight;


}

void freeAdjList(Node *adjList[], int vertex) {
    for (int i = 0; i < vertex; i++) {
        Node *temp = adjList[i];
        while (temp) {
            Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main(){
    
    int vertex , edge;
    printf("Enter the number of vertex & edges : ");
    scanf("%d%d" , &vertex , &edge);

    Node *adjList[100] = {NULL};

    printf("Enter edges (u , v , wt ): \n");

    for(int i = 0 ; i < edge ; i++){
        int u , v , wt;
        scanf("%d%d%d" , &u , &v , &wt);
        addEdge(adjList , u , v , wt);
    }

    int weight = primsMST(adjList , vertex , edge);

    printf("Total weight of MST: %d\n", weight);
    printf("Edges in MST:\n");

    for (int i = 1; i < vertex; i++) {
        printf("%d - %d\n", parent[i], i);
    }
    
    freeAdjList(adjList, vertex);
    return 0; 
}