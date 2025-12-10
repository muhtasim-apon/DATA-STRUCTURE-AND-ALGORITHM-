class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (auto y : arr)
        {
            long long dist = abs(y - x);
            // if(x<0)dist=y+x;
            // else dist=y-x;
            pq.push({dist, y});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};