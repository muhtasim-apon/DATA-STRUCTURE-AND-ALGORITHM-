// C++ program to check for Identical
// BSTs without building the trees
#include <bits/stdc++.h>
using namespace std;

// Function to check if two arrays construct the same BST
bool isSameBSTUtil(vector<int> &arr1, vector<int> &arr2,
                   int n, int l, int r, int low, int high)
{
    int leftIdx, rightIdx;

    // Search for a valid element in arr1 and arr2
    // that satisfies the constraints `low` and `high`
    for (leftIdx = l; leftIdx < n; leftIdx++)
    {
        if (arr1[leftIdx] > low && arr1[leftIdx] < high)
        {
            break;
        }
    }
    for (rightIdx = r; rightIdx < n; rightIdx++)
    {
        if (arr2[rightIdx] > low && arr2[rightIdx] < high)
        {
            break;
        }
    }

    // If both arrays have no valid elements, return true
    if (leftIdx == n && rightIdx == n)
    {
        return true;
    }

    // If one array has a valid element but the other doesn't,
    // or if the elements are different, return false
    if (((leftIdx == n) ^ (rightIdx == n)) || arr1[leftIdx] != arr2[rightIdx])
    {

        return false;
    }

    // Recursively check for the right and left subtrees
    return isSameBSTUtil(arr1, arr2, n, leftIdx + 1, rightIdx + 1,
                         arr1[leftIdx], high) &&
           isSameBSTUtil(arr1, arr2, n, leftIdx + 1, rightIdx + 1,
                         low, arr1[leftIdx]);
}

bool isSameBST(vector<int> &arr1, vector<int> &arr2,
               int n)
{
    return isSameBSTUtil(arr1, arr2, n, 0, 0,
                         INT_MIN, INT_MAX);
}

int main()
{

    // Hardcoded inputs for both the arrays
    vector<int> arr1 = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    vector<int> arr2 = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n = arr1.size();

    if (isSameBST(arr1, arr2, n))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}