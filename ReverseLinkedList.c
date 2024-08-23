// reverse a linked List
#include <stdio.h>
#include <stdlib.h>

// Node creation
struct Node
{
    int value;
    struct Node *link;
} *head = NULL, *headrev = NULL;

void reverse(struct Node *);
void insert(int);
void display(struct Node *);

int main()
{
    printf("Enter the 5 values of Linked list : ");
    for (int data, i = 1; i <= 5; i++)
    {
        scanf("%d", &data);
        insert(data);
    }
    printf("Before Reversing ");
    display(head);
    reverse(head);
    printf("\nAfter revesing ");
    display(headrev);
    return 0;
}

void insert(int data)
{
    struct Node *temp,*ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->value = data;
    ptr->link = NULL;
    if (head == NULL)
        head = ptr;
    else
    {
        temp = head;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = ptr;
        
    }
}

// reverse function

void reverse(struct Node *ptr)
{
    // base case
    if (ptr->link == NULL)
    {
        headrev = ptr;
        return;
    }

    reverse(ptr->link);

    // back track
    ptr->link->link = ptr;
    ptr->link = NULL;
}

// Display function
void display(struct Node *head1)
{
    struct Node *ptr;
        ptr = head1;
        printf("List elements : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->value);
            ptr = ptr->link;
        }
}