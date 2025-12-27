class Solution
{
public:
    bool isPalindrome(string s)
    {
        string s1, s2;
        for (auto x : s)
        {
            if (isalpha(x) || isdigit(x))
                s1 += tolower(x);
        }
        s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2)
            return true;
        return false;
    }
};