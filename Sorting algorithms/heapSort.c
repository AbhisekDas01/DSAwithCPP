#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;    
}
void heapify(int *arr , int i , int size){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[i] , &arr[largest]);
        heapify(arr , size , largest);
    }
}

void heapSort(int *arr , int size){
    for(int i = size/2 - 1 ; i >= 0 ; i--){
        heapify(arr , size , i);
    }
    for(int i = size - 1 ; i > 0 ; i--){
        swap(&arr[0] , &arr[i]);
        heapify(arr , 0 , i);
    }
}



// void printArray(int *arr , int size){
//     for(int i = 0 ; i < size ; i++){
//         printf("%d " , arr[i]);
//     }
//     printf("\n");
// }


int main(){

    int size;
    printf("Enter the size : ");
    scanf("%d" , &size);

    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    for(int i = 0 ; i < size ; i++){
        arr[i] = rand();
    }

    clock_t start, end;
    double  executionTime ;

    start = clock();
    // printArray(arr , size); 
    heapSort(arr , size);
    end = clock();
    
    executionTime = ((double)(end-start))/CLOCKS_PER_SEC;

    // printArray(arr , size);

    printf("Time taken to sort %d elements is : %lf seconds\n" , size , executionTime);

    free(arr);
    return 0;
}