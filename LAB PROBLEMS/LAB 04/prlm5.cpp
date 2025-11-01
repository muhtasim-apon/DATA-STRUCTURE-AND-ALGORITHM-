#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (true)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
int main()
{
    int n;
    cout << "Size of the array:\n";
    cin >> n;
    int arr[n];
    cout<<"Array Elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}