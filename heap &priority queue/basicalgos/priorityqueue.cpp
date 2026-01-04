#include <bits/stdc++.h>
using namespace std;

// ---------- Helper index functions ----------
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// ---------- Heapify UP ----------
void shiftUp(int i, vector<int> &pq)
{
    while (i > 0 && pq[parent(i)] < pq[i])
    {
        swap(pq[i], pq[parent(i)]);
        i = parent(i);
    }
}

// ---------- Heapify DOWN ----------
void shiftDown(int i, vector<int> &pq, int size)
{
    int maxIndex = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < size && pq[l] > pq[maxIndex])
        maxIndex = l;

    if (r < size && pq[r] > pq[maxIndex])
        maxIndex = r;

    if (i != maxIndex)
    {
        swap(pq[i], pq[maxIndex]);
        shiftDown(maxIndex, pq, size);
    }
}

// ---------- Insert ----------
void insertPQ(int value, vector<int> &pq)
{
    pq.push_back(value);
    shiftUp(pq.size() - 1, pq);
}

// ---------- Get Max ----------
int getMax(const vector<int> &pq)
{
    if (pq.empty())
    {
        cout << "Priority Queue is empty\n";
        return -1;
    }
    return pq[0];
}

// ---------- Extract Max ----------
int extractMax(vector<int> &pq)
{
    if (pq.empty())
    {
        cout << "Priority Queue is empty\n";
        return -1;
    }

    int result = pq[0];
    pq[0] = pq.back();
    pq.pop_back();
    shiftDown(0, pq, pq.size());

    return result;
}

// ---------- Increase Key ----------
void increaseKey(int index, int newValue, vector<int> &pq)
{
    if (index < 0 || index >= pq.size())
    {
        cout << "Invalid index\n";
        return;
    }
    pq[index] = newValue;
    shiftUp(index, pq);
}

// ---------- Decrease Key ----------
void decreaseKey(int index, int newValue, vector<int> &pq)
{
    if (index < 0 || index >= pq.size())
    {
        cout << "Invalid index\n";
        return;
    }
    pq[index] = newValue;
    shiftDown(index, pq, pq.size());
}

// ---------- Delete at index ----------
void deleteAt(int index, vector<int> &pq)
{
    if (index < 0 || index >= pq.size())
    {
        cout << "Invalid index\n";
        return;
    }
    increaseKey(index, INT_MAX, pq);
    extractMax(pq);
}

// ---------- Build Heap ----------
void buildHeap(vector<int> &pq)
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    pq.clear();
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push_back(x);
    }

    for (int i = pq.size() / 2 - 1; i >= 0; i--)
        shiftDown(i, pq, pq.size());
}

// ---------- Heap Sort ----------
void heapSort(vector<int> pq)
{
    cout << "Sorted (Descending): ";
    while (!pq.empty())
        cout << extractMax(pq) << " ";
    cout << endl;
}

// ---------- Display ----------
void display(const vector<int> &pq)
{
    if (pq.empty())
    {
        cout << "Priority Queue is empty\n";
        return;
    }

    cout << "Heap array: ";
    for (int x : pq)
        cout << x << " ";
    cout << endl;
}

// ---------- MAIN ----------
int main()
{
    vector<int> pq;
    int choice;

    do
    {
        cout << "\n----- PRIORITY QUEUE (MAX HEAP) -----\n";
        cout << "1. Insert\n";
        cout << "2. Get Max\n";
        cout << "3. Extract Max\n";
        cout << "4. Increase Key\n";
        cout << "5. Decrease Key\n";
        cout << "6. Delete at Index\n";
        cout << "7. Build Heap\n";
        cout << "8. Heap Sort\n";
        cout << "9. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            insertPQ(val, pq);
            break;
        }
        case 2:
            cout << "Max element: " << getMax(pq) << endl;
            break;

        case 3:
            cout << "Extracted: " << extractMax(pq) << endl;
            break;

        case 4:
        {
            int idx, val;
            cout << "Index and new value: ";
            cin >> idx >> val;
            increaseKey(idx, val, pq);
            break;
        }
        case 5:
        {
            int idx, val;
            cout << "Index and new value: ";
            cin >> idx >> val;
            decreaseKey(idx, val, pq);
            break;
        }
        case 6:
        {
            int idx;
            cout << "Enter index to delete: ";
            cin >> idx;
            deleteAt(idx, pq);
            break;
        }
        case 7:
            buildHeap(pq);
            break;

        case 8:
            heapSort(pq);
            break;

        case 9:
            display(pq);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
