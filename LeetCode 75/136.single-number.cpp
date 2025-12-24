class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // sort(nums.begin(),nums.end());
        int ans = 0;
        for (auto x : nums)
            ans = ans ^ x;
        return ans;
    }
};