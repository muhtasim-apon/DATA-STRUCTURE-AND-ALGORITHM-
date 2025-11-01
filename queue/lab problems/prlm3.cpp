//implementing a dequeue using doubly linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Queue{
    int data;
    struct Queue* prev;
    struct Queue* next;
};
struct Queue* front=NULL;
struct Queue* rear=NULL;
bool isEmpty()
{
    if(front==NULL)return true;
    return false;
}
void enqueueatrear(int val)
{
    struct Queue* newnode=(struct Queue*)malloc(sizeof(struct Queue));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=rear;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void enqueueafront(int val)
{
    struct Queue* newnode=(struct Queue*)malloc(sizeof(struct Queue));
    newnode->data=val;
    newnode->next=front;
    newnode->prev=NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        front->prev=newnode;
        front=newnode;
    }
}
int dequeuefront()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        struct Queue* temp=front;
        int popped=temp->data;
        front=front->next;
        if(front!=NULL)
        {
            front->prev=NULL;
        }
        else
        {
            rear=NULL;
        }
        free(temp);
        return popped;
    }
}
int dequeback()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        struct Queue* temp=rear;
        int popped=temp->data;
        rear=rear->prev;
        if(rear!=NULL)
        {
            rear->next=NULL;
        }
        else
        {
            front=NULL;
        }
        free(temp);
        return popped;
    }
}
int topfront()
{
    if(isEmpty())return -1;
    else
    {
        return front->data;
    }
}
int bottomback()
{
    if(isEmpty())return -1;
    else
    {
        return rear->data;
    }
}
void displayqueue()
{
     if(isEmpty())
     {
        cout<<"Queue is Empty!!!"<<"\n";
     }
     struct Queue* temp=front;
     while(temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->next;
     }
     cout<<"\n";
}
void displayReverse() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    struct Queue* temp=rear;
    printf("Deque elements (rear -> front): ");
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    int choice, val;
    do {
        printf("\nEnter Your choice:\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n");
        printf("5. Peek Front\n6. Peek Rear\n7. Display Deque\n8. Display Reverse\n9. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueueafront(val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueueatrear(val);
            break;

        case 3:
            val = dequeuefront();
            if (val != -1)
                printf("Deleted from front: %d\n", val);
            break;

        case 4:
            val = dequeback();
            if (val != -1)
                printf("Deleted from rear: %d\n", val);
            break;

        case 5:
            val = topfront();
            if (val != -1)
                printf("Front element: %d\n", val);
            break;

        case 6:
            val = bottomback();
            if (val != -1)
                printf("Rear element: %d\n", val);
            break;

        case 7:
            displayqueue();
            break;

        case 8:
            displayReverse();
            break;

        case 9:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}