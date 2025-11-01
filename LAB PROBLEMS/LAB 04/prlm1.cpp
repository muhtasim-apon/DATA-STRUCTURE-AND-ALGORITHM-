#include <bits/stdc++.h>
using namespace std;
bool binarysearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        mid = high + low / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
int searchmid(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        mid = high + low / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
int lowerbound(int arr[], int n, int key, int target)
{
    int lowerbound = -1;
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        mid = high + low / 2;
        if (arr[mid] == target)
        {
            lowerbound = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return lowerbound;
}
int upperbound(int arr[], int n, int key, int target)
{
    int upperbound = -1;
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        mid = high + low / 2;
        if (arr[mid] == target)
        {
            upperbound = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return upperbound;
}

int main()
{
    int n;
    cout << "Enter Size of the Array:\n";
    cin >> n;
    int arr[n];
    cout << "Input:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cout << "Target:\n";
    cin >> target;
    if (binarysearch(arr, n, target))
    {
        int set = searchmid(arr, n, target);
        int key = arr[set];
        int first = lowerbound(arr, n, key, target);
        int last = upperbound(arr, n, key, target);
        int occur = last - first + 1;
        cout << "Output:\n";
        cout << "First= " << first << ",Last= " << last << ",Count= " << occur << "\n";
    }
    else
    {
        cout << "Element not Found!!\n";
    }
}
