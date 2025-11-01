// Stack implementation using Linked List (Menu Driven)
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *head = NULL;

// Check if stack is empty
bool isEmpty() {
    return head == NULL;
}

// Push operation
void push(int val) {
    struct Stack *newnode = (struct Stack *)malloc(sizeof(struct Stack));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    //cout << val << " pushed to stack\n";
}

// Pop operation
int pop() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return -1;
    }
    struct Stack *temp = head;
    head = head->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Peek (top) operation
int top() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return head->data;
}

// Check if stack is full (always false in linked list)
bool isFull() {
    return false;
}

// Display stack
void displaystack() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return;
    }
    struct Stack *temp = head;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        cout << "\nEnter Your choice:\n"
             << "1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. Display Stack\n7. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int val;
            cout << "Enter the value to be pushed: ";
            cin >> val;
            push(val);
            break;
        }
        case 2: {
            int popped = pop();
            if (popped != -1)
                cout << "Popped element is: " << popped << "\n";
            break;
        }
        case 3: {
            int topval = top();
            if (topval != -1)
                cout << "Top element is: " << topval << "\n";
            break;
        }
        case 4:
            if (isEmpty())
                cout << "Stack is Empty\n";
            else
                cout << "Stack is not Empty\n";
            break;

        case 5:
            if (isFull())
                cout << "Stack is Full\n";
            else
                cout << "Stack is not Full\n";
            break;

        case 6:
            displaystack();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        }
    } while (choice != 7);

    return 0;
}

