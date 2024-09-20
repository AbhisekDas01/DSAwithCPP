#include <stdio.h>
#include <stdlib.h>

//Node creation
typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

//initialising head and tail
Node *head = NULL;
Node *tail = NULL;

int size = 0 ; //to store the count of nodes

//operations
Node *createNode();
void insertBegin();
void insertEnd();
void insertAtPos();
void deleteBegin();
void deleteEnd();
void deleteFromPos();
void display();
void displayReverse();

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
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insertBegin();    break;
        case 2: insertEnd();      break;
        case 3: insertAtPos();      break;
        case 4: deleteBegin();      break;
        case 5: deleteEnd();        break;
        case 6: deleteFromPos();    break;
        case 7: display();          break;
        case 8: printf("Exiting...") ;      break;
        default: printf("Invalid choice!");
        }
    } while (ch != 8);
    return 0;
}


//Node creation
Node *createNode()
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if(ptr == NULL){
        printf("Memory allocation failed!");
        return NULL;
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&ptr->value);
        ptr->prev = NULL;
        ptr->next = NULL;
        return ptr;
    }
}

//insert begin function
void insertBegin()
{
    Node *ptr = createNode();
    if(head == NULL)
    {
        head = ptr;
        head->next = head;
        head->prev = head;
        tail = head;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        head->prev = tail;
        tail->next = head;
    }
    size++;
}

//insert end
void insertEnd()
{
    Node *ptr = createNode();
    if(head == NULL)
    {
        head = ptr;
        head->next = head;
        head->prev = head;
        tail = head;
    }
    else
    {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
        tail->next = head;
        head ->prev = tail;
    }
    size++;
}

//insert at specific position
void insertAtPos()
{
    int pos;
    printf("Enter the position between 1 to %d : ",size+1);
    scanf("%d",&pos);
    if(pos < 1 || pos > size +1 )
        printf("Invalid position!");
    else
    {
        if(pos == 1)
            insertBegin();
        else if(pos == size+1)
            insertEnd();
        else
        {
            Node *ptr = createNode();
            Node *temp = head;
            int i;
            for(i = 1 ; i < pos-1 ; i++)
                temp = temp->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            temp->next = ptr;
            ptr->prev = temp;
            size++;
        }
    }
}

//delete Begin
void deleteBegin()
{
    if(head == NULL){
        printf("List empty!");
        return;
    }
    if(head == tail)
    {
        printf("Deleted %d ",head->value);
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        printf("Deleted %d",head->prev->value);
        free(head->prev);
        head->prev = tail;
        tail->next = head;
    }
    size--;
}

//delete end
void deleteEnd()
{
    if(head == NULL){
        printf("List empty!");
        return;
    }

    if(head == tail)
    {
        deleteBegin();
    }
    else
    {
        tail = tail->prev;
        printf("Deleted %d",tail->next->value);
        free(tail->next);
        head->prev = tail;
        tail->next = head;
        size--;
    }
}

//delete from specific position
void deleteFromPos()
{
    if(head == NULL)
        printf("List empty!");
    else
    {
        int pos;
        printf("Enter the position between 1 to %d : ",size);
        scanf("%d",&pos);
        if(pos < 1 || pos > size)
            printf("Invalid position!");
        else
        {
            if(pos == 1)
                deleteBegin();
            else if(pos == size)
                deleteEnd();
            else
            {
                Node *temp = head;
                int i;
                for(i = 1 ; i < pos-1 ; i++)
                    temp = temp->next;
                Node *ptr = temp->next;
                temp->next = ptr->next;
                ptr->next->prev = temp;
                printf("Deleted %d",ptr->value);
                free(ptr);
                size--;
            }
        }
    }
}


//display function
void display()
{
    if(head == NULL)
        printf("No elements!");
    else
    {
        printf("List elements : ");
        Node *ptr = head;
        do
        {
            printf("%d <-> ",ptr->value);
            ptr = ptr->next;
        } while(ptr != head);
        printf("head\n");

        char ch;
        printf("\n\nPrint list in reverse order (y/n): ");
        scanf(" %c",&ch);
        if(ch == 'y' || ch == 'Y')
            displayReverse();
    }
}

//display reverse
void displayReverse()
{
    Node *temp = tail;
    printf("List elements in reverse order : ");
    do
    {
        printf("%d <-> ",temp->value);
        temp = temp->prev;
    } while (temp != tail);
    printf("tail\n");
}
