class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        // code here
        priority_queue<pair<int, int>> pq;
        int n = *max_element(deadline.begin(), deadline.end());
        for (int i = 0; i < profit.size(); i++)
            pq.push({profit[i], deadline[i]});
        vector<int> ans(2, 0);
        vector<int> seq(n, -1);
        while (!pq.empty())
        {
            int a = pq.top().second;
            int b = pq.top().first;
            for (int i = a - 1; i >= 0; i--)
            {
                if (seq[i] == -1)
                {
                    seq[i] = b;
                    break;
                }
            }
            pq.pop();
        }
        for (int i = 0; i < n; i++)
        {
            if (seq[i] >= 1)
            {
                ans[0]++;
                ans[1] += seq[i];
            }
        }
        return ans;
    }
};