#include <bits/stdc++.h>
using namespace std;

// Find first occurrence of key
int firstOccurrence(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            ans = mid;      // store current index
            high = mid - 1; // search in left half
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

// Find last occurrence of key
int lastOccurrence(vector<int> &arr, int key)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            ans = mid;     // store current index
            low = mid + 1; // search in right half
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int key = 2;

    cout << "First occurrence of " << key << " is at index: " << firstOccurrence(arr, key) << endl;
    cout << "Last occurrence of " << key << " is at index: " << lastOccurrence(arr, key) << endl;

    return 0;
}
