//sorting an queue linked listimplimentizations
#include<bits/stdc++.h>
using namespace std;
struct  Node
{
    int val;
    Node* next;
};
Node* front=NULL;
Node* back=NULL;
void enqueue(int x)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->val=x;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=back=newnode;
        return;
    }
    back->next=newnode;
    back=newnode;
}
int dequeue()
{
    Node* temp=front;
    front=front->next;
    if(front==NULL)back=NULL;
    int val=temp->val;
    free(temp);
    return val;
}
void sortqueue()
{
    if(front==NULL)return;
    vector<int>v;
    while(front!=NULL)
    {
        v.push_back(dequeue());
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        enqueue(v[i]);
    } 
}
void printqueue()
{
    Node* temp=front;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    enqueue(5);
    enqueue(1);
    enqueue(3);
    enqueue(2);
    enqueue(4);
    cout<<"Original Queue: ";
    printqueue();
    sortqueue();
    cout<<"Sorted Queue: ";
    printqueue();
    return 0;
}
