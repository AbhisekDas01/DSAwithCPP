#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100


typedef struct Node
{
    int data , dist;
    struct Node *next;
} Node;

typedef struct heap{
    int dist , src;
} heap;

heap minHeap[MAX];   
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

    if(left < heapSize && minHeap[left].dist < minHeap[small].dist)
        small = left;
    if(right < heapSize && minHeap[right].dist < minHeap[small].dist)
        small = right;

    if(small != i){
        swap(i , small);
        minHeapify(small);
    }
}


Node* createNode(int data, int dist) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->dist = dist;
    newNode->next = NULL;
    return newNode;
}

void insert(int dist , int src){

    int i = heapSize++;
    minHeap[i].dist = dist;
    minHeap[i].src = src;


    while(i > 0){

        int parentIdx = (i-1)/2;

        if(minHeap[parentIdx].dist > minHeap[i].dist){
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


void addEdge(Node *adjList[] , int u , int v , int dist , int directed){

    //u->v
    Node *newNode = createNode(v , dist);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    if(!directed){
        //undirected graph v->u
        newNode = createNode(u ,dist);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

int* dijkstrasAlgo(Node *adjList[] , int vertex , int src){


    int* dist = (int*)malloc(vertex * sizeof(int));
    heapSize = 0; //initialise minHeap

    for(int i = 0 ; i < vertex ; i++) dist[i] = INT_MAX;

    dist[src] = 0;

    insert(0 , src);

    while (heapSize > 0)
    {
        heap curr = extractMin();

        int currDist = curr.dist;
        int currNode = curr.src;

        Node *adj = adjList[currNode];

        while(adj){
            int edgeWeight = adj->dist;
            int neibourNode = adj->data;

            if(currDist + edgeWeight < dist[neibourNode]){

                dist[neibourNode] = currDist + edgeWeight;
                insert(dist[neibourNode] , neibourNode);
            }

            adj = adj->next;
        }
    }

    return dist;
    

}


void freeAdj(Node *adjList[] , int vertex){
    for (int i = 0; i < vertex; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    
}


int main(){

    int vertex , edge , directed;
    printf("Enter the number of vertex & edges : ");
    scanf("%d%d" , &vertex , &edge);

    Node *adjList[100] = {NULL};

    printf("Is the graph directed ? (0 / 1): ");
    scanf("%d" , &directed);
    printf("Enter edges (u , v , dist ): \n");

    for(int i = 0 ; i < edge ; i++){
        int u , v , dist;
        scanf("%d%d%d" , &u , &v , &dist);
        addEdge(adjList , u , v , dist , directed);
    }

    printf("Enter the src : ");
    int src;
    scanf("%d" , &src);
    int *dist = dijkstrasAlgo(adjList , vertex ,  src);

    printf("Shortest path form %d are: \n" , src);
    for(int i = 0 ; i<vertex ;i++){
        printf("%d - %d\n",i , dist[i]);
    }

    freeAdj(adjList , vertex);
    free(dist);
    return 0;
}




