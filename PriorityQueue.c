#include <stdio.h>
#include <stdlib.h>
#define max 5

struct pqueuedata
{
    int value;
    int priority;
} pqueue[max]; //structure defination

int rear = -1;

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
    {
        printf("\nPriority Queue Overflow!");
    }
    else
    {
        rear++;
        printf("\nEnter the Element ans its Priority : ");
        scanf("%d%d",&pqueue[rear].value,&pqueue[rear].priority);
    }
}

//delete function
void delete()
{
    int hpriority;//it will store the element with highest priority
    int index = 0 ,i;
    if(rear == -1)
        printf("\nPriority queue Underflow!");
    else
    {
        hpriority = pqueue[0].priority; // let assume the index 0 is the highest priority
        for(i = 1 ; i <= rear ; i++)
        {
            if(pqueue[i].priority > hpriority)
            {
                hpriority = pqueue[i].priority;
                index = i;

            }
        }
        printf("Deleted %d",pqueue[index].value);
        //shift all the elements to fill the gap in array
        for(i = index ; i < rear ; i++)
        {
            pqueue[i].value = pqueue[i+1].value;
            pqueue[i].priority = pqueue[i+1].priority;
        }
        rear--;
        //to retrive the rear to -1 after the pqueue is full
        if(rear >= max)
            rear = -1;
    }
}

//display function
void display()
{
    int i ;
    if(rear == -1)
        printf("\nPriority queue Underflow!");
    else
    {
        printf("Priority Queue elements : ");
        for(i=0 ; i<= rear ; i++)
        {
            printf("%d ",pqueue[i].value);
        }
    }

}

