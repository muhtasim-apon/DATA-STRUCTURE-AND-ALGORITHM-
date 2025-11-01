
#include <iostream>
#include <stdlib.h>
using namespace std;
struct deque
{
    int data;
    struct deque *next;
    struct deque *prev;
};
struct deque *front = NULL;
struct deque *rear = NULL;

bool isEmpty()
{
    if (front == NULL)
        return true;
    return false;
}

void enqueueatback(int val)
{
    struct deque *newnode = (struct deque *)malloc(sizeof(struct deque));
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
void enqueueatfront(int val)
{
    struct deque *newnode = (struct deque *)malloc(sizeof(struct deque));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = front;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        front->prev = newnode;
        front = newnode;
    }
}
int dequeuefront()
{
    if (isEmpty())
        return -1;
    struct deque *temp = front;
    front = front->next;
    front->prev = NULL;
    int removed = temp->data;
    free(temp);
    return removed;
}
int dequeueback()
{
    if (isEmpty())
        return -1;
    struct deque *temp = rear;
    rear = rear->prev;
    rear->next = NULL;
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

void dispalyqueuefront()
{
    if (isEmpty())
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The elements of deque are:\n");
        struct deque *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void dispalyqueueback()
{
    if (isEmpty())
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The elements of deque are:\n");
        struct deque *temp = rear;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;
    do
    {
        printf("\nEnter your Choice:\n1.enqueueatfront\n2.enqueueatback\n3.dequeuefront\n4.dequeueback\n5.getfront\n6.getback\n7.check empty\n8.dispalyqueuefront\n9.dispalyqueueback\n10.Exit\n");
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            printf("Enter value to push from front in deque\n");
            int x;
            cin >> x;
            enqueueatfront(x);
            break;
        }
        case 2:
        {
            printf("Enter value to push from back in deque\n");
            int x;
            cin >> x;
            enqueueatback(x);
            break;
        }
        case 3:
        {
            int val = dequeuefront();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Dequeued value from front is %d\n", val);
            break;
        }
        case 4:
        {
            int val = dequeueback();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Dequeued value from back is %d\n", val);
            break;
        }
        case 5:
        {
            int val = getfront();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Front value is %d\n", val);
            break;
        }
        case 6:
        {
            int val = getback();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Rear value is %d\n", val);
            break;
        }
        case 7:
        {
            if (isEmpty())
                printf("Queue is Empty!!\n");
            else
                printf("Queue is Not Empty!!\n");
            break;
        }
        case 8:
        {
            dispalyqueuefront();
            break;
        }
        case 9:
        {
            dispalyqueueback();
            break;
        }
        case 10:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid Choice!!\n");
        }
        }
    } while (choice != 10 && choice >= 1 && choice <= 9);

    return 0;
}
