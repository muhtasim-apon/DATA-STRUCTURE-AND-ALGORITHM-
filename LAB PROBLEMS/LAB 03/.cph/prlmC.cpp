#include<iostream>
#include<stdlib.h>
using namespace std;
struct palindrome1{
    char letter;
    struct palindrome1 *next;
};
struct palindrome2{
    char letter1;
    struct palindrome2 *next1;
};
struct palindrome1 *head=NULL;
struct palindrome2 *front=NULL;
void push(char x)
{
    struct palindrome1 *newnode=(struct palindrome1*)malloc(sizeof(struct palindrome1));
    newnode->letter=x;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct palindrome1 *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}
void enqueue(char x)
{
    struct palindrome2 *newnode=(struct palindrome2*)malloc(sizeof(struct palindrome2));
    newnode->letter1=x;
    newnode->next1=NULL;
    if(front==NULL)
    {
        front=newnode;
        return;
    }
    newnode->next1=front;
    front=newnode;
}
bool checkpalindrome(string s)
{
    for(int i=0;i<s.size();i++)
    {
        push(s[i]);
        enqueue(s[i]);
    }
    struct palindrome1 *temp1=head;
    struct palindrome2 *temp2=front;
    while(temp1!=NULL && temp2!=NULL )
    {
        if(temp1->letter!=temp2->letter1)
        {
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next1;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    if(checkpalindrome(s))
    {
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}