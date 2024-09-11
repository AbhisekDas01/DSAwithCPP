#include <stdio.h>
#include <stdlib.h>

// Node creation

struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} *head = NULL;

int size = 0; // to store the number of the links
// functions

struct Node *createNode();
void insertAtBegin();
void insertAtend();
void insertAtPos();
void deleteBegin();
void deleteEnd();
void deleteFromPos();
void display();
void displayReverse(struct Node *);
void cleanup();

// main function
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
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insertAtBegin();    break;
        case 2: insertAtend();      break;
        case 3: insertAtPos();      break;
        case 4: deleteBegin();      break;
        case 5: deleteEnd();        break;
        case 6: deleteFromPos();    break;
        case 7: display();          break;
        case 8: cleanup();          break;
        default: printf("Invalid choice!");
        }
    } while (ch != 8);
    return 0;
}

// node creation

struct Node *createNode()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value : ");
    scanf("%d", &ptr->value);
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

// insert at begin
void insertAtBegin()
{
    struct Node *ptr = createNode();
    if (head == NULL)
        head = ptr;
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    size++;
    printf("Inserted at begin..");
}

// insert at end
void insertAtend()
{
    struct Node *ptr = createNode();
    if (head == NULL)
        head = ptr;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    size++;
    printf("Inserted at end..");
}

// insert from specific position
void insertAtPos()
{
    int pos;
    printf("Enter the position Between 1 to %d : ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1)
        printf("Invalid Position!");
    else
    {
        if (pos == 1)
            insertAtBegin();
        else if (pos == size + 1)
            insertAtend();
        else
        {
            struct Node *temp = head, *ptr = createNode();
            for (int i = 1; i < pos - 1; i++)
                temp = temp->next;

            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
            size++;
            printf("Inserted at %dth position..", pos);
        }
    }
}

// delete from begin

void deleteBegin()
{
    if (head == NULL)
    {
        printf("Empty list!");
        return;
    }

    struct Node *ptr = head;
    // if only one node present
    if (head->next == NULL)
        head = NULL;
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted %d from begin..", ptr->value);
    free(ptr);
    size--;
}

// delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        printf("Empty list!");
        return;
    }

    if (head->next == NULL)
    {
        deleteBegin();
        return;
    }

    // delete from pos
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted %d from end..", temp->value);
    free(temp);
    size--;
}

// delete from specific position
void deleteFromPos()
{
    if (head == NULL)
    {
        printf("List empty!");
        return;
    }

    int pos;
    printf("Enter the position Between 1 to %d : ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size)
    {
        printf("Invalid Position!");
        return;
    }

    if (pos == 1)
    {
        deleteBegin();
        return;
    }

    if (pos == size)
    {
        deleteEnd();
        return;
    }

    int i;
    struct Node *ptr = head, *temp;
    for (i = 1; i < pos - 1; i++)
        ptr = ptr->next;
    temp = ptr->next;

    ptr->next = temp->next;
    temp->next->prev = ptr;

    printf("Deleted %d from %dth position..", temp->value, pos);
    free(temp);

    size--;
}

void display()
{
    if (head == NULL)
    {
        printf("No elements!");
        return;
    }

    struct Node *ptr = head, *temp = head;
    printf("List elements : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;

        // for reverse print
        if (temp->next != NULL)
            temp = temp->next;
    }

    char c;
    printf("\nDisplay list in reverse order (y/n) : ");
    scanf(" %c", &c);

    if (c == 'y' || c == 'Y')
        displayReverse(temp);
}

// reverse print
void displayReverse(struct Node *tail)
{
    printf("\nList elements in reverse order : ");
    while (tail != NULL)
    {
        printf("%d ", tail->value);
        tail = tail->prev;
    }
}

//to clearing used memory
void cleanup()
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory cleaned up. Exiting...\n");
}
