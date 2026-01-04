#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* =====================================================
   COMMON NODE STRUCTURE
   ===================================================== */
struct Node
{
    int data;
    struct Node *next, *prev;
};

/* =====================================================
   SINGLY LINKED LIST
   ===================================================== */
struct Node *sHead = NULL;

struct Node *createNode(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = n->prev = NULL;
    return n;
}

void s_insert_head(int x)
{
    struct Node *n = createNode(x);
    n->next = sHead;
    sHead = n;
}

void s_insert_tail(int x)
{
    struct Node *n = createNode(x);
    if (!sHead)
    {
        sHead = n;
        return;
    }
    struct Node *t = sHead;
    while (t->next)
        t = t->next;
    t->next = n;
}

void s_delete_head()
{
    if (!sHead)
        return;
    struct Node *t = sHead;
    sHead = sHead->next;
    free(t);
}

void s_delete_tail()
{
    if (!sHead || !sHead->next)
    {
        free(sHead);
        sHead = NULL;
        return;
    }
    struct Node *t = sHead;
    while (t->next->next)
        t = t->next;
    free(t->next);
    t->next = NULL;
}

void s_display()
{
    struct Node *t = sHead;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void s_reverse()
{
    struct Node *prev = NULL, *cur = sHead, *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    sHead = prev;
}

void s_sort()
{
    struct Node *i, *j;
    for (i = sHead; i && i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data)
            {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

/* =====================================================
   CIRCULAR LINKED LIST
   ===================================================== */
struct Node *cHead = NULL;

void c_insert_end(int x)
{
    struct Node *n = createNode(x);
    if (!cHead)
    {
        cHead = n;
        n->next = n;
        return;
    }
    struct Node *t = cHead;
    while (t->next != cHead)
        t = t->next;
    t->next = n;
    n->next = cHead;
}

void c_display()
{
    if (!cHead)
        return;
    struct Node *t = cHead;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != cHead);
    printf("\n");
}

/* =====================================================
   DOUBLY LINKED LIST
   ===================================================== */
struct Node *dHead = NULL;

void d_insert_begin(int x)
{
    struct Node *n = createNode(x);
    n->next = dHead;
    if (dHead)
        dHead->prev = n;
    dHead = n;
}

void d_insert_end(int x)
{
    struct Node *n = createNode(x);
    if (!dHead)
    {
        dHead = n;
        return;
    }
    struct Node *t = dHead;
    while (t->next)
        t = t->next;
    t->next = n;
    n->prev = t;
}

void d_display_forward()
{
    struct Node *t = dHead;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void d_display_reverse()
{
    if (!dHead)
        return;
    struct Node *t = dHead;
    while (t->next)
        t = t->next;
    while (t)
    {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

/* =====================================================
   CIRCULAR QUEUE (ARRAY)
   ===================================================== */
int cq[MAX];
int front = -1, rear = -1;

int isFull()
{
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    cq[rear] = x;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Empty\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void cq_display()
{
    if (isEmpty())
        return;
    int i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/* =====================================================
   MAIN MENU
   ===================================================== */
int main()
{
    int ch, x;

    while (1)
    {
        printf("\n==== MAIN MENU ====\n");
        printf("1 Singly Linked List\n");
        printf("2 Circular Linked List\n");
        printf("3 Doubly Linked List\n");
        printf("4 Circular Queue\n");
        printf("0 Exit\n");
        scanf("%d", &ch);

        if (ch == 0)
            break;

        switch (ch)
        {
        case 1:
            printf("1 Insert Head 2 Insert Tail 3 Delete Head 4 Delete Tail 5 Display 6 Reverse 7 Sort\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), s_insert_head(x);
            if (ch == 2)
                scanf("%d", &x), s_insert_tail(x);
            if (ch == 3)
                s_delete_head();
            if (ch == 4)
                s_delete_tail();
            if (ch == 5)
                s_display();
            if (ch == 6)
                s_reverse();
            if (ch == 7)
                s_sort();
            break;

        case 2:
            printf("1 Insert End 2 Display\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), c_insert_end(x);
            if (ch == 2)
                c_display();
            break;

        case 3:
            printf("1 Insert Begin 2 Insert End 3 Display Forward 4 Display Reverse\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), d_insert_begin(x);
            if (ch == 2)
                scanf("%d", &x), d_insert_end(x);
            if (ch == 3)
                d_display_forward();
            if (ch == 4)
                d_display_reverse();
            break;

        case 4:
            printf("1 Enqueue 2 Dequeue 3 Display\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), enqueue(x);
            if (ch == 2)
                dequeue();
            if (ch == 3)
                cq_display();
            break;
        }
    }
    return 0;
}
