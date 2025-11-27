#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
    node *parent;
};

struct queuenode
{
    node *data;
    queuenode *next;
};

struct queue
{
    queuenode *front;
    queuenode *rear;
};

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(queue *q)
{
    return (q->front == NULL);
}

void enqueue(queue *q, node *val)
{
    queuenode *temp = (queuenode *)malloc(sizeof(queuenode));
    temp->data = val;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

node *dequeue(queue *q)
{
    if (isEmpty(q))
        return NULL;
    queuenode *temp = q->front;
    node *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void deletequeue(queue *q)
{
    if (!q)
        return;
    while (!isEmpty(q))
        dequeue(q);
    free(q);
}

struct Heap
{
    node *root;
    int size;

    node *createNode(int val)
    {
        node *n = (node *)malloc(sizeof(node));
        n->value = val;
        n->left = n->right = n->parent = NULL;
        return n;
    }

    node *insertpoint()
    {
        if (!root)
            return NULL;
        queue *q = createQueue();
        enqueue(q, root);
        while (!isEmpty(q))
        {
            node *cur = dequeue(q);
            if (!cur->left || !cur->right)
            {

                deletequeue(q);
                return cur;
            }
            enqueue(q, cur->left);
            enqueue(q, cur->right);
        }
        deletequeue(q);
        return NULL;
    }

    void heapup(node *nodePtr)
    {
        while (nodePtr->parent && nodePtr->value > nodePtr->parent->value)
        {
            int t = nodePtr->value;
            nodePtr->value = nodePtr->parent->value;
            nodePtr->parent->value = t;
            nodePtr = nodePtr->parent;
        }
    }

    void heapdown(node *nodePtr)
    {
        while (nodePtr)
        {
            node *biggest = nodePtr;
            if (nodePtr->left && nodePtr->left->value > biggest->value)
                biggest = nodePtr->left;
            if (nodePtr->right && nodePtr->right->value > biggest->value)
                biggest = nodePtr->right;
            if (biggest == nodePtr)
                break;
            int t = nodePtr->value;
            nodePtr->value = biggest->value;
            biggest->value = t;
            nodePtr = biggest;
        }
    }

    void insert(int val)
    {
        node *newNode = createNode(val);
        size++;
        if (!root)
        {
            root = newNode;
            return;
        }
        node *parent = insertpoint();
        newNode->parent = parent;
        if (!parent->left)
            parent->left = newNode;
        else
            parent->right = newNode;
        heapup(newNode);
    }

    node *findlast()
    {
        if (!root)
            return NULL;
        queue *q = createQueue();
        enqueue(q, root);
        node *last = NULL;
        while (!isEmpty(q))
        {
            last = dequeue(q);
            if (last->left)
                enqueue(q, last->left);
            if (last->right)
                enqueue(q, last->right);
        }
        deletequeue(q);
        return last;
    }

    node *search(int val)
    {
        if (!root)
            return NULL;
        queue *q = createQueue();
        enqueue(q, root);
        node *found = NULL;
        while (!isEmpty(q))
        {
            node *n = dequeue(q);
            if (n->value == val)
            {
                found = n;
                break;
            }
            if (n->left)
                enqueue(q, n->left);
            if (n->right)
                enqueue(q, n->right);
        }

        deletequeue(q);
        return found;
    }

    void deleteval(int val)
    {
        if (!root)
        {
            cout << "Heap is empty.\n";
            return;
        }

        node *target = search(val);
        if (!target)
        {
            cout << "Element not found.\n";
            return;
        }

        node *last = findlast();

        if (target == last)
        {
            if (last->parent)
            {
                if (last->parent->left == last)
                    last->parent->left = NULL;
                else
                    last->parent->right = NULL;
            }
            else
                root = NULL;
            free(last);
            size--;
            return;
        }

        target->value = last->value;
        if (last->parent->right == last)
            last->parent->right = NULL;
        else
            last->parent->left = NULL;
        free(last);
        size--;

        heapdown(target);
        heapup(target);
    }

    int Top()
    {
        if (!root)
            return -1;
        return root->value;
    }

    int Max()
    {
        if (!root)
            return -1;
        return root->value;
    }

    int Min()
    {
        if (!root)
            return -1;
        queue *q = createQueue();
        enqueue(q, root);
        int minVal = root->value;
        while (!isEmpty(q))
        {
            node *nd = dequeue(q);
            if (nd->value < minVal)
                minVal = nd->value;
            if (nd->left)
                enqueue(q, nd->left);
            if (nd->right)
                enqueue(q, nd->right);
        }
        deletequeue(q);
        return minVal;
    }

    void print()
    {
        if (!root)
        {
            cout << "Heap is empty.\n";
            return;
        }
        queue *q = createQueue();
        enqueue(q, root);
        cout << "Heap: ";
        while (!isEmpty(q))
        {
            node *nd = dequeue(q);
            cout << nd->value << " ";
            if (nd->left)
                enqueue(q, nd->left);
            if (nd->right)
                enqueue(q, nd->right);
        }
        deletequeue(q);
        cout << "\n";
    }
};

int main()
{
    Heap heap;
    heap.root = NULL;
    heap.size = 0;

    int choice, val;

    while (1)
    {
        cout << "1. Insert\n";
        cout << "2. Delete Element\n";
        cout << "3. View Top\n";
        cout << "4. Search Element\n";
        cout << "5. Find Max\n";
        cout << "6. Find Min\n";
        cout << "7. Print Heap\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            heap.insert(val);
            break;

        case 2:
            cout << "Enter value to deleteval: ";
            cin >> val;
            heap.deleteval(val);
            break;

        case 3:
            val = heap.Top();
            if (val == -1)
                cout << "Heap is empty.\n";
            else
                cout << "Top element: " << val << "\n";
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> val;
            if (heap.search(val))
                cout << "Element found.\n";
            else
                cout << "Element not found.\n";
            break;

        case 5:
            val = heap.Max();
            if (val == -1)
                cout << "Heap is empty.\n";
            else
                cout << "Max element: " << val << "\n";
            break;

        case 6:
            val = heap.Min();
            if (val == -1)
                cout << "Heap is empty.\n";
            else
                cout << "Min element: " << val << "\n";
            break;

        case 7:
            heap.print();
            break;

        case 8:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
