#include <stdio.h>
#include <stdlib.h>
// node creation
struct Node
{
    int value;
    struct Node *next;
} *head = NULL;


//nede craetion
struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->value = data;
        ptr->next = NULL;
    
    return ptr;
}

//find middle of the linked list 
struct Node* findMid(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

    }
    return slow;
}

void display()
{
    struct Node *ptr =  head;
    printf("List elements : ");
    while(ptr != NULL)
    {
        printf("%d -> ",ptr->value);
        ptr = ptr->next;
    }
    printf("NULL");
}
int main()
{
    head = createNode(12);
    head->next= createNode(45);
    head->next->next = createNode(78);
    head->next->next->next = createNode(90);
    head->next->next->next->next = createNode(100);
    display();

    int ans = findMid(head)->value;
    printf("\nMid element : %d" , ans);
    return 0;
}