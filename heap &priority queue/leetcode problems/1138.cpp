class Solution
{
public:
    map<int, int> freq;
    priority_queue<int> pq;
    int count = 0;
    int sum = 0;
    int minSetSize(vector<int> &arr)
    {
        for (auto x : arr)
            freq[x]++;
        for (auto x : freq)
            pq.push(x.second);
        while (!pq.empty())
        {
            sum = sum + pq.top();
            count++;
            pq.pop();
            if (sum >= arr.size() / 2)
                break;
        }
        return count;
    }
};