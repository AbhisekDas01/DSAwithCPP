#include <stdio.h>
#include <stdlib.h>
#define max 5
int cqueue[max];
int front = -1 , rear = -1;

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
            case 1: insert();  break;
            case 2: delete();  break;
            case 3: display(); break;
            case 4: exit(0);   break;
            default: printf("\nInvalid Choice ");
        }
    }
    return 0 ;
}

void insert()
{
    if((front == 0 && rear == max-1) || front == rear+1)
        printf("Circular Queue overflow!");
    else
    {

        printf("Enter the element : ");
        rear=(rear+1)%max;
        scanf("%d",&cqueue[rear]);
        if(front == -1)
            front = 0 ;
    }
}

//delete fuction

void delete()
{
    int val;
    if(front == -1)
        printf("Circular Queue Underflow!");
    else
    {

        printf("\nDeleted %d",cqueue[front]);
        if(front == rear)
          front = rear = -1;
        else
         front = (front +1)%max;
    }

}
//display function
void display()
{
    if(front == -1)
        printf("\nCircular Queue Underflow!");
    else
    {
        int i;
        printf("\nCircular Queue elements : ");
        for(i= front ; i != rear ; i = (i+1)%max)
            printf("%d ",cqueue[i]);
        printf("%d ",cqueue[rear]);

    }
}
