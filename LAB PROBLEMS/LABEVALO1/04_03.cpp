#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertfirst(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}
void push(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
struct queue
{
    int data;
    struct queue *next;
    struct queue *prev;
};
struct queue *front = NULL;
struct queue *rear = NULL;

bool isEmpty()
{
    if (front == NULL)
        return true;
    return false;
}
void enqueue(int val)
{
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->data = val;
    newnode->prev = rear;
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    if (isEmpty())
        return -1;
    struct queue *temp = front;
    front = front->next;
    int removed = temp->data;
    free(temp);
    return removed;
}

int getfront()
{
    if (isEmpty())
        return -1;
    return front->data;
}
int getback()
{

    if (isEmpty())
        return -1;
    return rear->data;
}

void sortarray(struct Node* head)
{
    int count=0;
    
     
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)push(i);
    for(int i=0;i<n;i++)
    {
        enqueue(i);
    }
    return 0;

}