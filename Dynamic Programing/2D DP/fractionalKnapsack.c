#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    double val1 = (double)item1->value / (double)item1->weight;
    double val2 = (double)item2->value / (double)item2->weight;

    if (val1 < val2) return 1;
    if (val1 > val2) return -1;
    return 0;
}

double fractionalKnapSack(Item *item, int size, int capacity) {
    if (capacity == 0 || size == 0) return 0.0;

    qsort(item, size, sizeof(Item), compare);

    int currentWeight = 0;
    double finalValue = 0;

    for (int i = 0; i < size; i++) {
        if (currentWeight + item[i].weight <= capacity) {
            currentWeight += item[i].weight;
            finalValue += item[i].value;
        } else {
            double remainingCapacity = capacity - currentWeight;
            double perUnitPrice = (double)item[i].value / (double)item[i].weight;
            double price = remainingCapacity * perUnitPrice;
            finalValue += price;
            break;
        }
    }

    return finalValue;
}

int main() {
    int size;

    printf("Enter the number of elements : ");
    scanf("%d", &size);

    Item *item = (Item *)malloc(size * sizeof(Item));

    if (item == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d values : \n", size);

    for (int i = 0; i < size; i++) {
        printf("value & weight of %d : ", i + 1);
        scanf("%d%d", &item[i].value, &item[i].weight);
    }

    int capacity;
    printf("Enter the capacity of knapsack : ");
    scanf("%d", &capacity);

    double profit = fractionalKnapSack(item, size, capacity);

    printf("The profit is : %.2lf", profit);

    free(item);
    return 0;
}