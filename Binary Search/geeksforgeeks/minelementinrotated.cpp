int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1; // min is in right half
        else
            high = mid; // min is at mid or left half
    }

    return arr[low];
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    cout << "Minimum element: " << findMin(arr) << endl;
    return 0;
}
