#include <stdio.h>
#include <string.h>

void selectionSort(char Name[5][30] , int n)
{
    char minValue[30];
    int minIndex;
    for (int i = 0; i < n-1; i++)
    {
        minIndex = i;
        strcpy(minValue , Name[i]);

        for (int j = i+1; j < n; j++)
        {
            if(strcmp(Name[j] , minValue) < 0)
            {
                strcpy(minValue, Name[j]);
                minIndex = j;
            }
        }

        //swap strings 
        if(minIndex != i)
        {
            char temp[30];
            strcpy(temp , Name[i]);
            strcpy(Name[i] , Name[minIndex]);
            strcpy(Name[minIndex] , temp);
        }
    }
    
}

void printString(char Name[5][30] , int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("%s" , Name[i]);
    }
}
int main()
{
    char Name[5][30];

    printf("Enter 5 names : ");
    for (int i = 0; i < 5; i++)
    {
        fgets(Name[i] , 30 , stdin);
    }

    printf("\nBefore sorting : \n");
    printString(Name,5);

    selectionSort(Name , 5);

    printf("\nAfter sorting : \n");
    printString(Name,5);
    
    
    
    return 0;
}