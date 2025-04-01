#include <stdio.h>
#include <stdlib.h>
typedef struct Item {
    int value;
    int weight;
} Item;

void swap(Item *a , Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item *item , int start , int end){

    double pivot = (double)item[end].value/(double)item[end].weight;
    int i = start;

    for(int j = start ; j < end ; j++){
        
        double value = (double)item[j].value/(double)item[j].weight;

        if(value >= pivot){
            swap(&item[i++] , &item[j]);
        }
    }

    swap(&item[i] , &item[end]);

    return i;
}
void quickSort(Item *item , int start , int end){

    if(start >= end) return;

    int pivot = partition(item , start , end);

    quickSort(item , start , pivot-1);
    quickSort(item , pivot+1 , end);

}

//fractional knapsack solution
double fractionalKnapSack(Item *item , int size , int capacity){

    
}

int main()
{
    int size;

    printf("Enter the number of elements : ");
    scanf("%d" , &size);

    Item *item = (Item *)malloc(size * sizeof(Item));

    printf("Enter %d values : \n",size);

    for(int i = 0 ; i < size ;i++){

        printf("value & weight of %d : " , i+1);
        scanf("%d%d" , &item[i].value , &item[i].weight);
    }

    int capacity;
    printf("Enter the capacity of knapsack : ");
    scanf("%d" , &capacity);

    //sort in decending order
    quickSort(item , 0 , size-1);

    free(item);
    return 0;
}