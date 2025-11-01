#include <iostream>
#include <stdlib.h>
using namespace std;

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

void dispalyqueue()
{
    if (isEmpty())
    {
        printf("Queue is Empty!!\n");
    }
    else
    {
        printf("The elements of queue are:\n");
        struct queue *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;
    do
    {
        printf("\nEnter your Choice:\n1.enqueue\n2.dequeue\n3.getfront\n4.getback\n5.check empty\n6.display queue\n7.Exit\n");
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            printf("Enter value to push in queue\n");
            int x;
            cin >> x;
            enqueue(x);
            break;
        }
        case 2:
        {
            int val = dequeue();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Dequeued value is %d\n", val);
            break;
        }
        case 3:
        {
            int val = getfront();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Front value is %d\n", val);
            break;
        }
        case 4:
        {
            int val = getback();
            if (val == -1)
                printf("Queue is Empty!!\n");
            else
                printf("Rear value is %d\n", val);
            break;
        }
        case 5:
        {
            if (isEmpty())
                printf("Queue is Empty!!\n");
            else
                printf("Queue is Not Empty!!\n");
            break;
        }
        case 6:
        {
            dispalyqueue();
            break;
        }
        case 7:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid Choice!!\n");
        }
        }
    } while (choice != 7 && choice >= 1 && choice <= 6);

    return 0;
}
