class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            int first = nums[i];
            // freq[nums[i]]=i;
            int second = target - first;
            if (count.find(second) != count.end())
            {
                ans.push_back(i);
                ans.push_back(count[second]);
                return ans;
            }
            else
                count[first] = i;
        }
        return ans;
    }
};