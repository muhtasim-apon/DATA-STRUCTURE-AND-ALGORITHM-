class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long sum = 0;
        sort(happiness.rbegin(), happiness.rend());
        for (int i = 0; i < k; i++)
        {
            happiness[i] -= i;
            if (happiness[i] <= 0)
                continue;
            else
            {
                sum += happiness[i];
            }
        }
        return sum;
    }
};