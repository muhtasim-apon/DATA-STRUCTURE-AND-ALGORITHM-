#include <bits/stdc++.h>
using namespace std;

vector<int> maxHeap;

// Index helpers
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// Heapify DOWN
void maxHeapify(int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < maxHeap.size() && maxHeap[l] > maxHeap[largest])
        largest = l;

    if (r < maxHeap.size() && maxHeap[r] > maxHeap[largest])
        largest = r;

    if (largest != i)
    {
        swap(maxHeap[i], maxHeap[largest]);
        maxHeapify(largest);
    }
}

// Heapify UP
void heapifyUpMax(int i)
{
    while (i > 0 && maxHeap[parent(i)] < maxHeap[i])
    {
        swap(maxHeap[i], maxHeap[parent(i)]);
        i = parent(i);
    }
}

// Insert
void insertKeyMax(int key)
{
    maxHeap.push_back(key);
    heapifyUpMax(maxHeap.size() - 1);
}

// Get Maximum
int getMax()
{
    return maxHeap[0];
}

// Extract Maximum
int extractMax()
{
    int root = maxHeap[0];
    maxHeap[0] = maxHeap.back();
    maxHeap.pop_back();
    maxHeapify(0);
    return root;
}

// Increase Key
void increaseKeyMax(int i, int newVal)
{
    maxHeap[i] = newVal;
    heapifyUpMax(i);
}

// Decrease Key
void decreaseKeyMax(int i, int newVal)
{
    maxHeap[i] = newVal;
    maxHeapify(i);
}

// Delete Key
void deleteKeyMax(int i)
{
    increaseKeyMax(i, INT_MAX);
    extractMax();
}

// Build Heap
void buildMaxHeap(vector<int> &arr)
{
    maxHeap = arr;
    for (int i = maxHeap.size() / 2 - 1; i >= 0; i--)
        maxHeapify(i);
}

// Heap Sort (Descending order)
vector<int> heapSortDesc()
{
    vector<int> backup = maxHeap;
    vector<int> sorted;

    while (!maxHeap.empty())
        sorted.push_back(extractMax());

    maxHeap = backup;
    return sorted;
}
