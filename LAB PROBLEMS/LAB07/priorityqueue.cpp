#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    char data;
    int freq;
    node *left;
    node *right;
    node *parent;
};

struct qnode
{
    node *data;
    qnode *next;
};

struct queue
{
    qnode *front;
    qnode *rear;
};

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(queue *q)
{
    return q->front == NULL;
}

void enqueue(queue *q, node *val)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
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
    qnode *temp = q->front;
    node *data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

struct PriorityQueue
{
    node *root;
    int size;

    node *createNode(char ch, int f)
    {
        node *n = (node *)malloc(sizeof(node));
        n->data = ch;
        n->freq = f;
        n->left = n->right = n->parent = NULL;
        return n;
    }

    node *insertPoint()
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
                while (!isEmpty(q))
                    dequeue(q);
                free(q);
                return cur;
            }
            enqueue(q, cur->left);
            enqueue(q, cur->right);
        }
        free(q);
        return NULL;
    }

    void heapUp(node *n)
    {
        while (n->parent && n->freq > n->parent->freq)
        {
            int tf = n->freq;
            char tc = n->data;
            n->freq = n->parent->freq;
            n->data = n->parent->data;
            n->parent->freq = tf;
            n->parent->data = tc;
            n = n->parent;
        }
    }

    void heapDown(node *n)
    {
        while (n)
        {
            node *largest = n;
            if (n->left && n->left->freq > largest->freq)
                largest = n->left;
            if (n->right && n->right->freq > largest->freq)
                largest = n->right;
            if (largest == n)
                break;
            int tf = n->freq;
            char tc = n->data;
            n->freq = largest->freq;
            n->data = largest->data;
            largest->freq = tf;
            largest->data = tc;
            n = largest;
        }
    }

    void insert(char ch, int f)
    {
        node *newNode = createNode(ch, f);
        size++;
        if (!root)
        {
            root = newNode;
            return;
        }
        node *parent = insertPoint();
        newNode->parent = parent;
        if (!parent->left)
            parent->left = newNode;
        else
            parent->right = newNode;
        heapUp(newNode);
    }

    node *findLast()
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
        free(q);
        return last;
    }

    node *search(char ch)
    {
        if (!root)
            return NULL;
        queue *q = createQueue();
        enqueue(q, root);
        while (!isEmpty(q))
        {
            node *cur = dequeue(q);
            if (cur->data == ch)
            {
                free(q);
                return cur;
            }
            if (cur->left)
                enqueue(q, cur->left);
            if (cur->right)
                enqueue(q, cur->right);
        }
        free(q);
        return NULL;
    }

    void deleteSpecific(char ch)
    {
        if (!root)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }

        node *target = search(ch);
        if (!target)
        {
            cout << "Character not found.\n";
            return;
        }

        node *last = findLast();

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

        target->freq = last->freq;
        target->data = last->data;

        if (last->parent->right == last)
            last->parent->right = NULL;
        else
            last->parent->left = NULL;

        free(last);
        size--;

        heapDown(target);
        heapUp(target);
    }

    void viewTop()
    {
        if (!root)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }
        cout << "Top Element: " << root->data << " (freq: " << root->freq << ")\n";
    }

    void findMax()
    {
        if (!root)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }
        cout << "Max Frequency: " << root->freq << " (" << root->data << ")\n";
    }

    void findMin()
    {
        if (!root)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }
        queue *q = createQueue();
        enqueue(q, root);
        int minf = root->freq;
        char mind = root->data;
        while (!isEmpty(q))
        {
            node *n = dequeue(q);
            if (n->freq < minf)
            {
                minf = n->freq;
                mind = n->data;
            }
            if (n->left)
                enqueue(q, n->left);
            if (n->right)
                enqueue(q, n->right);
        }
        cout << "Min Frequency: " << minf << " (" << mind << ")\n";
        free(q);
    }

    void display()
    {
        if (!root)
        {
            cout << "Priority Queue is empty.\n";
            return;
        }
        queue *q = createQueue();
        enqueue(q, root);
        cout << "Priority Queue: ";
        while (!isEmpty(q))
        {
            node *n = dequeue(q);
            cout << "(" << n->data << "," << n->freq << ") ";
            if (n->left)
                enqueue(q, n->left);
            if (n->right)
                enqueue(q, n->right);
        }
        cout << "\n";
        free(q);
    }
};

int main()
{
    PriorityQueue pq;
    pq.root = NULL;
    pq.size = 0;

    int choice;
    char ch;
    int freq;

    while (true)
    {
        cout << "1. Insert (char, freq)\n";
        cout << "2. Delete Specific Character\n";
        cout << "3. View Top\n";
        cout << "4. Search Character\n";
        cout << "5. Find Max\n";
        cout << "6. Find Min\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter character: ";
            cin >> ch;
            cout << "Enter frequency: ";
            cin >> freq;
            pq.insert(ch, freq);
            break;

        case 2:
            cout << "Enter character to delete: ";
            cin >> ch;
            pq.deleteSpecific(ch);
            break;

        case 3:
            pq.viewTop();
            break;

        case 4:
            cout << "Enter character to search: ";
            cin >> ch;
            if (pq.search(ch))
                cout << "Character found.\n";
            else
                cout << "Character not found.\n";
            break;

        case 5:
            pq.findMax();
            break;

        case 6:
            pq.findMin();
            break;

        case 7:
            pq.display();
            break;

        case 8:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
