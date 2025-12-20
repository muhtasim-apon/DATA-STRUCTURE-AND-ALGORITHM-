class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        // vector<vector<string>>strs;
        int ans = 0;
        // for(auto x: strs)strs.push_back(x);
        int len1 = strs.size();
        int len2 = strs[0].size();
        for (int i = 0; i < len2; i++)
        {
            bool test = true;
            for (int j = 0; j < len1 - 1; j++)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    test = false;
                    break;
                }
            }
            if (!test)
                ans++;
        }
        return ans;
    }
};