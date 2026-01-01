class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        digits.back() = digits.back() + 1;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = 0;
            sum += carry;
            sum += digits[i];
            carry = sum / 10;
            if (carry)
            {
                // carry=sum/10;
                sum %= 10;
                ans.push_back(sum);
            }
            else
            {
                ans.push_back(sum);
            }
        }
        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};