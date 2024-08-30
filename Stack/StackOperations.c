#include <stdio.h>
#include <stdlib.h>
#define max 5
int stack[max];
int top = -1;

void push()
{
    if(top  == max -1)
        printf("\nStack Overflow !");
    else
    {
        printf("\nEnter the element : ");
        scanf("%d" ,&stack[++top]);
    }
}
void pop()
{
    if(top == -1)
        printf("\nStack is empty !");
    else
        printf("\nDeleted %d",stack[top--]);
}
void peep()
{
    if(top == -1)
        printf("\nStack is empty !");
    else
        printf("\nTop element : %d",stack[top]);
}
void display()
{
    int i;
    if(top == -1)
        printf("\nStack is empty ! ");
    else
    {
        printf("\nStack elements : ");
        for(i = top ; i >= 0 ; i--)
            printf("%d\n" , stack[i]);
    }
}
int main()
{
    printf("Select the operation :\n");
    printf("1.push()\n2.pop()\n3.peep()\n4.display()\n5.exit()");
    int op;
    while (1)
    {
        printf("\nChoice : ");
        scanf("%d",&op);
        switch (op)
        {
        case 1: push();    break;
        case 2: pop();     break;
        case 3: peep();    break;
        case 4: display(); break;
        case 5: exit(0);   break;
        
        default: printf("\nInvalid choice"); break;
        }
    }
    
    return 0;
}
