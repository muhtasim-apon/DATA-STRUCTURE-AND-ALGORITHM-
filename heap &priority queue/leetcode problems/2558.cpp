class Solution
{
public:
        long long pickGifts(vector<int> &gifts, int k)
    {
        while (k--)
        {
            heapsort(gifts);
            reverse(gifts.begin(), gifts.end());
            gifts[0] = sqrt(gifts[0]);
        }
        long long sum = accumulate(gifts.begin(), gifts.end(), 0LL);
        return sum;
    }
};