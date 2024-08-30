#include <stdio.h>
#include <stdlib.h>
//Node creation
struct Node
{
    int value;
    struct Node *link;
}*head1 = NULL , *head2 = NULL;

struct Node * insert(struct Node * ,int);
void display(struct Node *);

int main()
{
    int val1 , val2,i;
    for(i = 1 ; i <= 5; i++)
    {
        printf("Enter the %dth element of list 1 & 2 : ",i);
        scanf("%d%d",&val1,&val2);
        head1 = insert(head1 ,val1);
        head2 = insert(head2 ,val2);

    }
    //merge function
    struct Node *temp = head1;
    printf("\nList 1 : ");
    display(head1);
    printf("\nList 2 : ");
    display(head2);
    while(temp->link != NULL)
        temp = temp->link;
    temp->link = head2;
    printf("\nMerged List : ");
    display(head1);

    return 0;
}
//insert function
struct Node * insert(struct Node *head ,int value)
{
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->value = value;
    ptr->link = NULL;
    if(head == NULL)
        head = ptr;
    else
    {
        ptr->link = head;
        head = ptr;
    }
    return head;

}

//display
void display(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->value);
        ptr = ptr->link;

    }
}
