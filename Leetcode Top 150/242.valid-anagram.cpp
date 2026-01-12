class Solution
{
public:
    map<char, int> freq;
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        for (auto x : s)
            freq[x]++;
        for (auto x : t)
        {
            if (freq[x] <= 0)
                return false;
            freq[x]--;
        }
        return true;
    }
};