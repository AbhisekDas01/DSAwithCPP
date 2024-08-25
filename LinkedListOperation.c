#include <stdio.h>
#include <stdlib.h>
// node creation
struct Node
{
    int value;
    struct Node *link;
} *head = NULL;

int size = 0; // to store the size of the list

struct Node *insert();
void insertBegin();
void insertEnd();
void insertAtpos();
void deleteBegin();
void deleteEnd();
void deleteAtpos();
void display();

int main()
{
    int op;
    printf("Enter the operation : ");
    printf("\n1.Insert At Begin\n2.Insert At End\n3.Insert At Specific Position\n4.Display");
    printf("\n5.Delete From Begin\n6.Delete From End\n7.Delete From Specific Position\n8.exit()");

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:  insertBegin();        break;
        case 2:  insertEnd();          break;
        case 3:  insertAtpos();        break;
        case 4:  display();            break;
        case 5:  deleteBegin();        break;
        case 6:  deleteEnd();          break;
        case 7:  deleteAtpos();        break;
        case 8:  printf("Exiting....... :)");  break;
        default: printf("Invalid choice!");    break;
        }
    } while (op != 8);

    return 0;
}

// insert function
struct Node *insert()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
        printf("Memory allocation failed! ");
    else
    {
        printf("Enter the value : ");
        scanf("%d", &ptr->value);
        ptr->link = NULL;
    }
    return ptr;
}

// insert Begin
void insertBegin()
{
    struct Node *ptr = insert();
    if (head == NULL)
        head = ptr;
    else
    {
        ptr->link = head;
        head = ptr;
    }
    size++;
}

// insert at end
void insertEnd()
{
    struct Node *temp, *ptr = insert();
    if (head == NULL)
        head = ptr;
    else
    {
        temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = ptr;
    }
    size++;
}

// insert at pos
void insertAtpos()
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
            struct Node *temp, *ptr = insert();
            temp = head;
            for (int i = 1; i < pos - 1; i++)
                temp = temp->link;
            ptr->link = temp->link;
            temp->link = ptr;
            size++;
        }
    }
}

// delete at begin

void deleteBegin()
{
    struct Node *ptr;
    if (head == NULL)
        printf("Empty List!");
    else
    {
        ptr = head;
        head = head->link;
        printf("Deleted %d", ptr->value);
        free(ptr);
        size--;
    }
}

// delete end
void deleteEnd()
{
    struct Node *ptr, *temp;
    if (head == NULL)
        printf("Empty list! ");
    else if (head->link == NULL)
    {
        deleteBegin();
    }
    else
    {
        ptr = head;
        while (ptr->link->link != NULL)
            ptr = ptr->link;
        temp = ptr->link;
        ptr->link = NULL;
        printf("Deleted %d", temp->value);
        free(temp);
        size--;
    }
}

// delete at position
void deleteAtpos()
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
                struct Node *ptr, *temp;
                ptr = head;
                for (int i = 1; i < pos - 1; i++)
                    ptr = ptr->link;
                temp = ptr->link;
                ptr->link = temp->link;
                temp->link = NULL;
                printf("Deleted %d", temp->value);
                free(temp);
                size--;
            }
        }
    }
}

// Display function
void display()
{
    struct Node *ptr;
    if (head == NULL)
        printf("No elements! ");
    else
    {
        ptr = head;
        printf("List elements : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->value);
            ptr = ptr->link;
        }
    }
}