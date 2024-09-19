#include <stdio.h>

void selectionSort2DArray(int arr[][100], int row, int col) {
    int size = row * col;
    for (int i = 0; i < size - 1; i++) {
        int minRow = i / col;
        int minCol = i % col;
        int minValue = arr[minRow][minCol];
        for (int j = i + 1; j < size; j++) {
            int tempRow = j / col;
            int tempCol = j % col;
            int tempValue = arr[tempRow][tempCol];
            if (minValue > tempValue) {
                minRow = tempRow;
                minCol = tempCol;
                minValue = tempValue;
            }
        }
        // Swap arr[i/col][i%col] with arr[minRow][minCol]
        if (minRow != i / col || minCol != i % col) { // Only swap if they are different
            int temp = arr[i / col][i % col];
            arr[i / col][i % col] = arr[minRow][minCol];
            arr[minRow][minCol] = temp;
        }
    }
}

void print2DArray(int arr[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[3][100] = {
        {64, 25, 12},
        {22, 11, 90},
        {5, 8, 30}
    };
    
    int row = 3, col = 3;

    printf("Original array:\n");
    print2DArray(arr, row, col);

    selectionSort2DArray(arr, row, col);

    printf("\nSorted array:\n");
    print2DArray(arr, row, col);

    return 0;
}