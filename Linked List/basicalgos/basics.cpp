#include <stdio.h>
#include <stdlib.h>

/* ================= NODE ================= */
struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

/* =====================================================
   NORMAL SINGLY LINKED LIST
   ===================================================== */
struct Node *head = NULL;

/* Insert */
void insertHead(int x)
{
    struct Node *n = createNode(x);
    n->next = head;
    head = n;
}

void insertTail(int x)
{
    struct Node *n = createNode(x);
    if (!head)
    {
        head = n;
        return;
    }
    struct Node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

/* Delete */
void deleteHead()
{
    if (!head)
        return;
    struct Node *t = head;
    head = head->next;
    free(t);
}

void deleteTail()
{
    if (!head || !head->next)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head;
    while (t->next->next)
        t = t->next;
    free(t->next);
    t->next = NULL;
}

/* Display */
void display()
{
    struct Node *t = head;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

/* Length */
int length()
{
    int c = 0;
    struct Node *t = head;
    while (t)
    {
        c++;
        t = t->next;
    }
    return c;
}

/* Reverse */
void reverse()
{
    struct Node *prev = NULL, *cur = head, *nxt;
    while (cur)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}

/* Sort (Bubble Sort) */
void sortList()
{
    if (!head)
        return;
    struct Node *i, *j;
    for (i = head; i->next; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data)
            {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

/* Find Middle */
void findMiddle()
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow)
        printf("Middle: %d\n", slow->data);
}

/* Remove Duplicates (Sorted List) */
void removeDuplicates()
{
    struct Node *t = head;
    while (t && t->next)
    {
        if (t->data == t->next->data)
        {
            struct Node *del = t->next;
            t->next = del->next;
            free(del);
        }
        else
            t = t->next;
    }
}

/* =====================================================
   CIRCULAR LINKED LIST
   ===================================================== */
struct Node *chead = NULL;

/* Insert at Beginning */
void c_insert_begin(int x)
{
    struct Node *n = createNode(x);
    if (!chead)
    {
        chead = n;
        n->next = n;
        return;
    }
    struct Node *t = chead;
    while (t->next != chead)
        t = t->next;
    n->next = chead;
    t->next = n;
    chead = n;
}

/* Insert at End */
void c_insert_end(int x)
{
    struct Node *n = createNode(x);
    if (!chead)
    {
        chead = n;
        n->next = n;
        return;
    }
    struct Node *t = chead;
    while (t->next != chead)
        t = t->next;
    t->next = n;
    n->next = chead;
}

/* Delete from Beginning */
void c_delete_begin()
{
    if (!chead)
        return;
    if (chead->next == chead)
    {
        free(chead);
        chead = NULL;
        return;
    }
    struct Node *t = chead;
    while (t->next != chead)
        t = t->next;
    struct Node *del = chead;
    chead = chead->next;
    t->next = chead;
    free(del);
}

/* Delete from End */
void c_delete_end()
{
    if (!chead)
        return;
    if (chead->next == chead)
    {
        free(chead);
        chead = NULL;
        return;
    }
    struct Node *t = chead;
    while (t->next->next != chead)
        t = t->next;
    free(t->next);
    t->next = chead;
}

/* Display Circular */
void c_display()
{
    if (!chead)
        return;
    struct Node *t = chead;
    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while (t != chead);
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
        printf("\n===== MAIN MENU =====\n");
        printf("1. Singly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("0. Exit\n");
        scanf("%d", &ch);

        if (ch == 0)
            break;

        if (ch == 1)
        {
            printf("\n1 Insert Head\n2 Insert Tail\n3 Delete Head\n4 Delete Tail\n");
            printf("5 Display\n6 Reverse\n7 Sort\n8 Middle\n9 Remove Duplicates\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), insertHead(x);
            if (ch == 2)
                scanf("%d", &x), insertTail(x);
            if (ch == 3)
                deleteHead();
            if (ch == 4)
                deleteTail();
            if (ch == 5)
                display();
            if (ch == 6)
                reverse();
            if (ch == 7)
                sortList();
            if (ch == 8)
                findMiddle();
            if (ch == 9)
                removeDuplicates();
        }

        if (ch == 2)
        {
            printf("\n1 Insert Begin\n2 Insert End\n3 Delete Begin\n4 Delete End\n5 Display\n");
            scanf("%d", &ch);
            if (ch == 1)
                scanf("%d", &x), c_insert_begin(x);
            if (ch == 2)
                scanf("%d", &x), c_insert_end(x);
            if (ch == 3)
                c_delete_begin();
            if (ch == 4)
                c_delete_end();
            if (ch == 5)
                c_display();
        }
    }
    return 0;
}
