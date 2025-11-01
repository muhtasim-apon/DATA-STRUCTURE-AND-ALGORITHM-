// Problem A

// You need to find the index (0-based) of a given key in an array.
// Input:
// First line: n, a number. (1<=n<=10^5)
// Next n lines: an integer v (-2147483648<=v <=2147483647)
// Next line: m, a number (1<=m<=10^5), the number of keys.
// Next m lines: an integer q (-2147483648<= q <=2147483647), the key to be searched for.
// Output:
// m lines, each containing the index of the keys. If element is not found print -1.
// Sample Case:
// Input Output
// 5
// -3
// -4
// 2
// 6
// 7
// 3
// -4
// 6
// 1

// 1
// 3
// -1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Key found
        }
        else if (arr[mid] < key) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Key not found
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // Ensure the array is sorted for binary search

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int key;
        cin >> key;
        int result = binarySearch(arr, key);
        cout << result << endl;
    }

    return 0;
}