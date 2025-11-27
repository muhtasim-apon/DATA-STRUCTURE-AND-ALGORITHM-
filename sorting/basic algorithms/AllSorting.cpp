#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

// 1️⃣ Bubble Sort
void bubbleSort(vector<int> arr) {
    cout << "Bubble Sort: ";
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    printArray(arr);
}

// 2️⃣ Selection Sort
void selectionSort(vector<int> arr) {
    cout << "Selection Sort: ";
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
    printArray(arr);
}

// 3️⃣ Insertion Sort
void insertionSort(vector<int> arr) {
    cout << "Insertion Sort: ";
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
    printArray(arr);
}

// 4️⃣ Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
void mergeSortDriver(vector<int> arr) {
    cout << "Merge Sort: ";
    mergeSort(arr, 0, arr.size() - 1);
    printArray(arr);
}

// 5️⃣ Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void quickSortDriver(vector<int> arr) {
    cout << "Quick Sort: ";
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);
}

// 6️⃣ Counting Sort (for non-negative ints)
void countingSort(vector<int> arr) {
    cout << "Counting Sort: ";
    int maxEl = *max_element(arr.begin(), arr.end());
    vector<int> count(maxEl + 1, 0);
    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= maxEl; i++)
        while (count[i]--) arr[index++] = i;
    printArray(arr);
}

// 7️⃣ Radix Sort
int getMax(vector<int> arr) {
    return *max_element(arr.begin(), arr.end());
}
void countSortForRadix(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};
    for (int num : arr) count[(num / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}
void radixSort(vector<int> arr) {
    cout << "Radix Sort: ";
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortForRadix(arr, exp);
    printArray(arr);
}

// 8️⃣ Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int> arr) {
    cout << "Heap Sort: ";
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    printArray(arr);
}

// 🧠 MAIN FUNCTION
int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    cout << "Original Array: ";
    printArray(arr);
    cout << "----------------------------------\n";

    bubbleSort(arr);
    selectionSort(arr);
    insertionSort(arr);
    mergeSortDriver(arr);
    quickSortDriver(arr);
    countingSort(arr);
    radixSort(arr);
    heapSort(arr);

    return 0;
}
