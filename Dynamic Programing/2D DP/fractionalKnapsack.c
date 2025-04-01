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

    if(capacity == 0 || size == 0) return 0.0;
    //sort in decending order
    quickSort(item , 0 , size-1);

    int currentWeight = 0; //it stores the total weight of taken items in knapsack
    double finalValue = 0; //it stores the total value of knapsack items

    for(int i = 0 ; i < size ;i++){

        //if the weight of the item is less than the capacity remaining then take it  
        if(currentWeight + item[i].weight <= capacity){

            currentWeight += item[i].weight; //add the weight
            finalValue += item[i].value;
        }else{
            //if item weight exceeds the capacity then take the fraction of it
            double remainingCapacity = capacity - currentWeight;
            double perUnitPrice = (double)item[i].value/(double)item[i].weight;

            double price = remainingCapacity * perUnitPrice;

            finalValue += price;
        }
    }

    return finalValue;

}

int main()
{
    int size;

    printf("Enter the number of elements : ");
    scanf("%d" , &size);

    Item *item = (Item *)malloc(size * sizeof(Item));

    if (item == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d values : \n",size);

    for(int i = 0 ; i < size ;i++){

        printf("value & weight of %d : " , i+1);
        scanf("%d%d" , &item[i].value , &item[i].weight);
    }

    int capacity;
    printf("Enter the capacity of knapsack : ");
    scanf("%d" , &capacity);

    double profit = fractionalKnapSack(item , size , capacity);

    printf("The profit is : %.2lf" , profit);
    

    free(item);
    return 0;
}