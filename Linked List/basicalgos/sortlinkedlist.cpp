#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertEnd(struct Node *head, int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (head == NULL)
        return n;

    struct Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
    return head;
}

void bubbleSort(struct Node *head)
{
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = head; j->next != NULL; j = j->next)
        {
            if (j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void display(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    bubbleSort(head);

    printf("Sorted List:\n");
    display(head);

    return 0;
}
