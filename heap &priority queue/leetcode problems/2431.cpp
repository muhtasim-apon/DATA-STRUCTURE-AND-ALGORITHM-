class Solution
{
public:
    int digitsum(int num)
    {
        int c = num, sum = 0;
        while (c > 0)
        {
            int d = c % 10;
            sum = sum + d;
            c = c / 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        int ans = -1;
        if (nums.size() == 1)
            return -1;
        priority_queue<pair<int, int>> pq;
        for (auto x : nums)
        {
            int sum1 = digitsum(x);
            pq.push({sum1, x});
        }
        while (pq.size() > 1)
        {
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            int c = pq.top().first;
            int d = pq.top().second;
            if (c == a)
                ans = max(ans, b + d);
        }
        return ans;
    }
};