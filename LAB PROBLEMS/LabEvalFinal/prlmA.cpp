#include <bits/stdc++.h>

struct node
{
    int val;
    struct node *next;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct node *head = NULL, *rear = NULL;

    for (int i = 0; i < n; i++)
    {
        int p, v;
        scanf("%d %d", &p, &v);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->val = v;
        newnode->next = NULL;

        if (head == NULL)
        {

            head = rear = newnode;
        }
        else if (p == 0)
        {

            newnode->next = head;
            head = newnode;
        }
        else
        {

            rear->next = newnode;
            rear = newnode;
        }
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->val);
        temp = temp->next;
    }

    return 0;
}
