#include <stdio.h>
#include <stdlib.h>
// linked list node creation

struct Stack
{
    int value;
    struct Stack *link;
};

// top pointer
struct Stack *top = NULL;

void push();
void pop();
void display();

int main()
{
    int op;
    printf("Enter the operation : ");
    printf("\n1.push()\n2.pop()\n3.display()\n4.exit()");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1: push();    break;
        case 2: pop();     break;
        case 3: display(); break;
        case 4:            break;
        default: 
            printf("Invalid choice!");
            break;
        }
    } while (op != 4);

    return 0;
}

//push operation 
void push()
{
    struct Stack *ptr = (struct Stack *) malloc(sizeof(struct Stack));
    //if memory allocation failed 
    if(ptr == NULL)
    {
        printf("Memory Allocation failed!");
        return;
    }   
    else
    {
        printf("Enter the element : ");
        scanf("%d",&ptr->value);
        ptr->link = NULL;
        if(top == NULL)
            top = ptr; 
        else
        {
            ptr->link= top ; 
            top = ptr;
        }
    }
}

//pop opertion
void pop()
{
    if(top == NULL)
        printf("Stack Underflow!");
    else
    {
        struct Stack *ptr;
        printf("\nDeleted %d",top->value);
        ptr = top; 
        top = top->link;
        free(ptr);
    }
}

//display 
void display()
{
    if(top == NULL)
        printf("Stack Underflow!");
    else
    {
        struct Stack *ptr;
        ptr = top; 
        printf("Stack elements : ");
        while(ptr != NULL)
        {
            printf("%d " , ptr->value);
            ptr = ptr->link;
        }
    }
}