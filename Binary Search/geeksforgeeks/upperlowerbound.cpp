int lowerBound(vector<int> &arr, int key)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upperBound(vector<int> &arr, int key)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= key)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
