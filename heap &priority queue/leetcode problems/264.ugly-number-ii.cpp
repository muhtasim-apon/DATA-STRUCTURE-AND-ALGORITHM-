#include <vector>
#include <algorithm>
#include <initializer_list>
/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> ugly(n);
        ugly[0] = 1;

        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; ++i)
        {
            int next_ugly_by_2 = ugly[p2] * 2;
            int next_ugly_by_3 = ugly[p3] * 3;
            int next_ugly_by_5 = ugly[p5] * 5;

            ugly[i] = min({next_ugly_by_2, next_ugly_by_3, next_ugly_by_5});

            if (ugly[i] == next_ugly_by_2)
            {
                p2++;
            }
            if (ugly[i] == next_ugly_by_3)
            {
                p3++;
            }
            if (ugly[i] == next_ugly_by_5)
            {
                p5++;
            }
        }

        return ugly[n - 1];
    }
};
// @lc code=end
