#include <stdio.h>
#include <stdlib.h>

//Node creation
struct Node
{
    int value;
    struct Node *link;
} *head = NULL , *tail = NULL;

int size = 0; //To store the size of the list

//operations
struct Node *createNode();
void insertBegin();
void insertEnd();
void insertAtPos();
void deleteBegin();
void deleteEnd();
void deleteFromPos();
void display();

//main function
int main()
{
    int ch;
    printf("Enter the operation : ");
    printf("\n1.insert at begin\n2.insert at end\n3.insert at specific position");
    printf("\n4.delete from begin\n5.delete from end\n6.delete from specific position");
    printf("\n7.display()\n8.exit()");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: insertBegin(); break;
        case 2: insertEnd();   break;
        case 3: insertAtPos();  break;
        case 4: deleteBegin();  break;
        case 5: deleteEnd();    break;
        case 6: deleteFromPos(); break;
        case 7: display();          break;
        case 8: printf("Exiting.... :) ");  break;
        default: printf("Invalid choice!");
        }
    }
    while(ch != 8);
    return 0 ;
}

//node creation
struct Node *createNode()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value : ");
    scanf("%d",&ptr->value);
    ptr->link = NULL;
    return ptr;
}

//insert begin function
void insertBegin()
{
    struct Node *ptr = createNode();
    if(head == NULL)
    {
        head = ptr;
        head->link = head;
        tail = head;
    }
    else
    {
        ptr->link = head;
        head = ptr;
        tail->link = head;
    }
    printf("Inserted at begin..\n");
    size++;
}

//insert at end
void insertEnd()
{
    struct Node *ptr = createNode();
    if(head == NULL)
    {
        head = ptr;
        head->link = head;
        tail = head;
    }
    else
    {
        tail->link = ptr;
        tail = ptr;
        tail->link = head;
    }
    size++;
    printf("Inserted at end..\n");
}

//insert at position
void insertAtPos()
{
    int pos;
    printf("\nEnter the position Between 1 to %d : ", size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1)
        printf("\nInvalid Position!");
    else
    {
        if (pos == 1)
            insertBegin();
        else if (pos == size + 1)
            insertEnd();
        else
        {
            int i ;
            struct Node *temp, *ptr = createNode();
            temp = head;
            for (i = 1; i < pos - 1; i++)
                temp = temp->link;
            ptr->link = temp->link;
            temp->link = ptr;
            size++;
            printf("Inserted at %dth postion..\n",pos);
        }
    }
}

//delete begin
void deleteBegin()
{
    if(head == NULL)
        printf("List empty!");
    else
    {
        struct Node *ptr = head;
        //if only one node present
        if(head ->link == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
           head = head->link;
           tail->link = head;
        }
        printf("Deleted %d from begin..",ptr->value);
        free(ptr);
        size--;
    }
}

//delete end function
void deleteEnd()
{
    if(head == NULL)
        printf("List empty!");
    else
    {
        //if only one node present
        if(head ->link == head)
            deleteBegin();
        else
        {
            struct Node *ptr = head;
            while(ptr->link != tail)
                ptr = ptr->link;

            ptr->link = head;
            printf("Deleted %d from end..",tail->value);
            free(tail);
            tail = ptr;
            size--;
        }
    }
}

//delete from position
void deleteFromPos()
{
    if (head == NULL)
        printf("Empty List! ");
    else
    {
        int pos;
        printf("\nEnter the position Between 1 to %d : ", size);
        scanf("%d", &pos);
        if (pos < 1 || pos > size)
            printf("\nInvalid Position!");
        else
        {
            if (pos == 1)
                deleteBegin();
            else if (pos == size)
                deleteEnd();
            else
            {
                int i;
                struct Node *ptr = head , *temp;
                for (i = 1; i < pos - 1; i++)
                    ptr = ptr->link;
                temp = ptr->link;
                ptr->link = temp->link;
                temp->link = NULL;
                printf("Deleted %d from %dth position..", temp->value,pos);
                free(temp);
                size--;
            }
        }
    }
}

void display()
{
    if(head == NULL)
        printf("No elements!");
    else
    {
        struct Node *ptr = head;
        printf("List elements : ");
        do
        {
            printf("%d -> ",ptr->value);
            ptr = ptr->link;
        } while(ptr != head);
        printf("head\n");
    }
}
