class Solution
{
public:
    vector<int> nums;
    // applying heap sort
    void heapify(vector<int> &nums, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[largest] < nums[left])
            largest = left;
        if (right < n && nums[largest] < nums[right])
            largest = right;
        if (largest != i)
        {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            heapify(nums, n, largest);
        }
    }
    void heapsort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
            heapify(nums, i, 0);
        }
    }

    int maxProduct(vector<int> &nums)
    {
        heapsort(nums);
        reverse(nums.begin(), nums.end());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};