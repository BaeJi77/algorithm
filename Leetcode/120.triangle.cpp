/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        for (int i = 0; i < 210; i++)
        {
            for (int j = 0; j < 210; j++)
            {
                dp[i][j] = minValue;
            }
        }

        return func(triangle, 0, 0);
    }

private:
    int dp[210][210];
    int minValue = -3000000;

    int func(vector<vector<int> > &t, int len, int now)
    {
        if (t.size() == len)
        {
            return 0;
        }

        if (dp[len][now] != minValue)
        {
            return dp[len][now];
        }

        return dp[len][now] = t[len][now] + min(func(t, len + 1, now), func(t, len + 1, now + 1));
    }
};
// @lc code=end
