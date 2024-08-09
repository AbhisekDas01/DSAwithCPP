#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front = -1 , rear = -1 ;
void insert();
void delete();
void display();

int main()
{
    printf("Enter the operation : ");
    printf("\n1.insert()\n2.delete()\n3.display()\n4.exit()");
    while(1)
    {
        int op;
        printf("\nEnter your choice : ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice ");
        }
    }
    return 0 ;
}
//insert function
void insert()
{
    if(rear == max-1)
        printf("\nQueue Overflow!");
    else
    {
        printf("\nEnter the value : ");
        scanf("%d",&queue[++rear]);
        if(front == -1)
            front = 0 ;
    }
}
//delete function

void delete()
{
    if((front == -1) || front > rear)
        printf("\nQueue underflow!");
    else
    {
        printf("Deleted %d",queue[front++]);
        if(front > rear)
            front = rear = -1;
    }
}
//display fuction
void display()
{
    int i;
    if((front == -1 ) || front > rear)
        printf("\nQueue underflow!");
    else
    {
        printf("\nQueue Elements : ");
        for(i=front ; i<= rear; i++)
            printf("%d ",queue[i]);
    }
}

