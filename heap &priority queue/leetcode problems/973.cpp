class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<long, vector<int>>> pq;
        for (auto x : points)
        {
            long long dist = 1LL * x[0] * x[0] + 1LL * x[1] * x[1];
            pq.push({dist, x});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};