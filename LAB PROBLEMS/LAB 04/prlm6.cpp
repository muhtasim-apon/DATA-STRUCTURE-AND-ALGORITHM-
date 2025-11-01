#include <bits/stdc++.h>
using namespace std;
long long comparisons = 0;
long long swaps = 0;
void reset()
{
    comparisons = 0;
    swaps = 0;
}
vector<long long> arr(long long n, int min = 0, int max = 10000)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);
    return arr;
}
int partition(vector<long long> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (true)
    {
        while (i <= high && arr[i] <= pivot)
        {
            comparisons++;
            i++;
        }
        while (j >= low && arr[j] > pivot)
        {
            comparisons++;
            j--;
        }
        if (i >= j)
            break;
        swap(arr[i], arr[j]);
        swaps++;
    }
    swap(arr[low], arr[j]);
    swaps++;
    return j;
}
void quicksortalgo(vector<long long> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quicksortalgo(arr, low, p - 1);
        quicksortalgo(arr, p + 1, high);
    }
}
void quicksort(vector<long long> &arr)
{
    quicksortalgo(arr, 0, arr.size() - 1);
}
void bubblesort(vector<long long> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}
void selectionsort(vector<long long> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        if (index != i)
        {
            swap(arr[i], arr[index]);
            swaps++;
        }
    }
}
void merge(vector<long long> &arr, int l, int m, int r)
{
    int l1 = m - l + 1;
    int l2 = r - m;
    vector<long long> L(l1), R(l2);
    for (int i = 0; i < l1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < l2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < l1 && j < l2)
    {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        swaps++;
    }
    while (i < l1)
    {
        arr[k++] = L[i++];
        swaps++;
    }
    while (j < l2)
    {
        arr[k++] = R[j++];
        swaps++;
    }
}
void mergesortalgo(vector<long long> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesortalgo(arr, l, m);
        mergesortalgo(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void mergesort(vector<long long> &arr)
{
    mergesortalgo(arr, 0, arr.size() - 1);
}
void insertionsort(vector<long long> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int target = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comparisons && arr[j] > target))
        {
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = target;
    }
}
void print(string technique, long long n, long long comparisons, long long swaps)
{
    cout << setw(15) << left << technique << "| Comparisons: " << setw(10) << comparisons << "Swaps: " << swaps << "\n";
}
int main()
{
    vector<long long> size = {10, 100, 1000};
    for (int n : size)
    {
        cout << "\n Array Size: " << n << " \n";
        vector<long long> randomarr = arr(n);
        cout << "Sorted array: ";
        vector<long long> temp = randomarr;
        bubblesort(temp);
        for (int i = 0; i < n; i++)
            cout << temp[i] << " ";
        cout << "\n";
        vector<long long> arr1 = randomarr;
        reset();
        bubblesort(arr1);
        print("Bubble Sort", n, comparisons, swaps);
        vector<long long> arr2 = randomarr;
        reset();
        insertionsort(arr2);
        print("Insertion Sort", n, comparisons, swaps);
        vector<long long> arr3 = randomarr;
        reset();
        selectionsort(arr3);
        print("Selection Sort", n, comparisons, swaps);
        vector<long long> arr4 = randomarr;
        reset();
        mergesort(arr4);
        print("Merge Sort", n, comparisons, swaps);
        vector<long long> arr5 = randomarr;
        reset();
        quicksort(arr5);
        print("Quick Sort", n, comparisons, swaps);
    }
}
