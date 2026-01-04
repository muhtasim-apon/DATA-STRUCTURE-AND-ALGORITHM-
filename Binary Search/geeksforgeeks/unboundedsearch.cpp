#include <bits/stdc++.h>
using namespace std;

// Standard binary search in [low, high]
int binarySearch(vector<int> &arr, int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Unbounded / Exponential Search
int unboundedBinarySearch(vector<int> &arr, int key)
{
    if (arr[0] == key)
        return 0;

    int i = 1;
    // Find range where key may exist
    while (i < arr.size() && arr[i] < key)
        i *= 2;

    // Binary search in found range
    int low = i / 2;
    int high = min(i, (int)arr.size() - 1);

    return binarySearch(arr, low, high, key);
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 12, 15, 18, 20};
    int key = 12;

    int index = unboundedBinarySearch(arr, key);
    if (index != -1)
        cout << "Element " << key << " found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
