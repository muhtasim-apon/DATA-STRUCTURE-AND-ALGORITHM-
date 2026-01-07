class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double avg = -1e9;
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        avg = max(avg, sum / (double)k);
        for (int i = k; i < nums.size(); i++)
        {
            sum = sum - nums[i - k] + nums[i];
            avg = max(avg, sum / (double)k);
        }
        return avg;
    }
};