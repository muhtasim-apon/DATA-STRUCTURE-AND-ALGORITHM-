class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> freq;
        set<int> s;
        for (auto x : arr)
        {
            freq[x]++;
        }
        for (auto x : freq)
        {
            s.insert(x.second);
        }
        if (s.size() == freq.size())
            return true;
        return false;
    }
};