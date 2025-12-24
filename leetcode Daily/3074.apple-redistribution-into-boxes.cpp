class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        long long sum = accumulate(apple.begin(), apple.end(), 0LL);
        sort(capacity.rbegin(), capacity.rend());
        long long sum1 = 0, count = 0;
        for (auto x : capacity)
        {
            sum1 += x;
            count++;
            if (sum1 >= sum)
                break;
        }
        return count;
    }
};