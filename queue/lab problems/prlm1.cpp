#include <stdio.h>

long int rear=-1, front=-1, size=0;

void enqueue(long int x, long int queue[], long int N) {
    if(size==N) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    size++;
    if(front==-1) front=0;
    queue[rear]=x;
}

long int dequeue(long int queue[]) {
    if(size==0) {
        printf("Queue is empty!!\n");
        return -1;
    }
    long int x=queue[front];
    front++;
    size--;
    if(size==0) { // reset if empty
        front=rear=-1;
    }
    return x;
}

long int getrear(long int queue[]) {
    if(size==0) {
        printf("Queue is empty!!\n");
        return -1;
    }
    return queue[rear];
}

long int getfront(long int queue[]) {
    if(size==0) {
        printf("Queue is empty!!\n");
        return -1;
    }
    return queue[front];
}

void checkempty() {
    if(size==0)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void checkfull(long int N) {
    if(size==N)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
}

void displayqueue(long int queue[]) {
    if(size==0) {
        printf("Queue is empty!!\n");
        return;
    }
    for(int i=front;i<=rear;i++) {
        printf("%ld ",queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    long int val;
    long int N;

    printf("Enter size of queue: ");
    scanf("%ld",&N);

    long int queue[N]; // define array

    do {
        printf("\nEnter Your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek Front\n4. Peek Rear\n5. Display Queue\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%ld", &val);
            enqueue(val,queue,N);
            break;

        case 2:
            val = dequeue(queue);
            if (val != -1)
                printf("Dequeued element is: %ld\n", val);
            break;

        case 3:
            val = getfront(queue);
            if (val != -1)
                printf("Front element is: %ld\n", val);
            break;

        case 4:
            val = getrear(queue);
            if (val != -1)
                printf("Rear element is: %ld\n", val);
            break;

        case 5:
            displayqueue(queue);
            break;

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
