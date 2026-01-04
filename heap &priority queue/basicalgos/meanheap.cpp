#include <bits/stdc++.h>
using namespace std;

vector<int> minHeap;

// Index helpers
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// Heapify DOWN
void minHeapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < minHeap.size() && minHeap[l] < minHeap[smallest])
        smallest = l;

    if (r < minHeap.size() && minHeap[r] < minHeap[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(minHeap[i], minHeap[smallest]);
        minHeapify(smallest);
    }
}

// Heapify UP
void heapifyUp(int i)
{
    while (i > 0 && minHeap[parent(i)] > minHeap[i])
    {
        swap(minHeap[i], minHeap[parent(i)]);
        i = parent(i);
    }
}

// Insert
void insertKey(int key)
{
    minHeap.push_back(key);
    heapifyUp(minHeap.size() - 1);
}

// Get Minimum
int getMin()
{
    return minHeap[0];
}

// Extract Minimum
int extractMin()
{
    int root = minHeap[0];
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    minHeapify(0);
    return root;
}

// Decrease Key
void decreaseKey(int i, int newVal)
{
    minHeap[i] = newVal;
    heapifyUp(i);
}

// Increase Key
void increaseKey(int i, int newVal)
{
    minHeap[i] = newVal;
    minHeapify(i);
}

// Delete Key
void deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// Build Heap from array
void buildMinHeap(vector<int> &arr)
{
    minHeap = arr;
    for (int i = minHeap.size() / 2 - 1; i >= 0; i--)
        minHeapify(i);
}

// Heap Sort (Ascending order)
vector<int> heapSortAsc()
{
    vector<int> backup = minHeap;
    vector<int> sorted;

    while (!minHeap.empty())
        sorted.push_back(extractMin());

    minHeap = backup;
    return sorted;
}
