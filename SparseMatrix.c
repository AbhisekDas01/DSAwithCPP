#include <stdio.h>


int main()
{
    int matrix[20][20] , sMatrix[50][3];
    int row , col;

    printf("Enter size of the row and col : ");
    scanf("%d%d" , &row , &col);

    printf("Enter the matrix elements.. \n");
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            printf("Matrix[%d][%d] : ",i,j);
            scanf("%d" , &matrix[i][j]);
        }
    }

    //counting the number of non zeros..
    int count = 0 ;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][j] != 0)
            {
                count++;
            }
        }
        
    }

    if(count  < (row*col)/2)
    {
        printf("Its a sparse matrix..");

        sMatrix[0][0] = row; //storing the number of rows
        sMatrix[0][1] = col; //number of cols
        sMatrix[0][2] = count; //number of non zeros

        int k = 1;
        
        for(int i = 0 ; i < row ; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(matrix[i][j] != 0)
                {
                    sMatrix[k][0] = i;
                    sMatrix[k][1] = j;
                    sMatrix[k][2] = matrix[i][j];
                    k++;
                }
            }
            
        }

        //printing the new matrix
        printf("\nSparse matrix...\n");
        for(int i = 0 ; i < k ; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d " , sMatrix[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Not a sparse matrix..");


    return 0;
}
