#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        // Left half sorted
        if (arr[low] <= arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half sorted
        else
        {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1; // not found
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int target = 3;

    int index = searchRotated(arr, target);
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
