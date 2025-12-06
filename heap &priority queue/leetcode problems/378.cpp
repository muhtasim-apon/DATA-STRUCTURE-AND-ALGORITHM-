class Solution
{
public:
    priority_queue<int> pq;
    bool test = false;
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        sort(matrix.begin(), matrix.end());
        for (auto x : matrix)
        {
            for (auto y : x)
            {
                pq.push(y);
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};