#include <stdio.h>
#include <stdlib.h>

//linked list creation 
struct Queue
{
    int value ; 
    struct Queue *link;
};

//front & rear 
struct Queue *front = NULL , *rear = NULL;

void insert();
void delete();
void display();

int main()
{
    int op;
    printf("Enter the operation : ");
    printf("\n1.insert()\n2.delete()\n3.display()\n4.exit()");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: insert();    break;
        case 2: delete();     break;
        case 3: display(); break;
        case 4:            break;
        default: 
            printf("Invalid choice!");
            break;
        }
    } while (op != 4);

    return 0;
}

//insert 
void insert()
{
    //node creation 
    struct Queue *ptr = (struct Queue *) malloc(sizeof(struct Queue));
    //if memory allocation fails 
    if(ptr == NULL)
    {
        printf("Memory Allocation failed!");
        return;
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d" , &ptr->value);
        ptr->link = NULL;
        //if Queue is empty
        if(front == NULL)
        {
            front = ptr; 
            rear = ptr ;
        }
        else
        {
            rear->link = ptr; 
            rear = ptr; 
        }
    }
}

//delete
void delete()
{
    if(front == NULL)
        printf("Queue empty!");
    else
    {
        printf("Deleted %d",front->value);
        struct Queue *ptr;
        ptr = front;
        front = front->link;
        free(ptr); 

        //if Queue Becomes empty 
        if(front == NULL)
            rear = NULL;

    }
}

void display()
{
    if(front == NULL)
        printf("Queue empty!");
    else
    {
        struct Queue *ptr; 
        ptr = front;
        printf("Queue elements : ");
        while(ptr != NULL)
        {
            printf("%d ",ptr->value);
            ptr = ptr->link;
        }
    }
}