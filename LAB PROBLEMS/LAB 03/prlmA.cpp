#include<stdio.h>
#include<stdlib.h>
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
   // printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int p,v;
        scanf("%d %d",&p,&v);
        if(p==0)
        {
            insertfirst(v);
        }
        else
        {
            push(v);
        }
    }
    display();
    return 0;

}