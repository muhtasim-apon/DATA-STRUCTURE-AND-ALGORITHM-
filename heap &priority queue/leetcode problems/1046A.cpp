class Solution
{
public:
    vector<int> stones;
    priority_queue<int> pq;
    int lastStoneWeight(vector<int> &stones)
    {
        for (int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b)
            {
                a = a - b;
                pq.push(a);
            }
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};