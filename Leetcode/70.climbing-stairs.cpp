/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int dp[50];

    int climbStairs(int n)
    {

        for (int i = 0; i < 50; i++)
        {
            dp[i] = -1;
        }

        return func(n, 0);
    }

    int func(int n, int idx)
    {
        if (n < idx)
        {
            return 0;
        }
        if (n == idx)
        {
            return 1;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        return dp[idx] = func(n, idx + 1) + func(n, idx + 2);
    }
};
// @lc code=end
