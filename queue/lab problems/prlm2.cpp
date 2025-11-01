//implementing a queue using doubly linked list
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
void enqueue(int val)
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
    }
}
int dequeue()
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
        if(front->next!=NULL)
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
int main() {
    int choice, val;

    do {
        printf("\nEnter Your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek Front\n4. Peek Rear\n5. Display Queue\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            val = dequeue();
            if (val != -1)
                printf("Dequeued element is: %d\n", val);
            break;

        case 3:
            val = topfront();
            if (val != -1)
                printf("Front element is: %d\n", val);
            break;

        case 4:
            val = bottomback();
            if (val != -1)
                printf("Rear element is: %d\n", val);
            break;

        case 5:
            displayqueue();
            break;

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}