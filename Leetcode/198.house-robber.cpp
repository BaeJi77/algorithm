/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = -1;
            }
        }

        return func(nums, 0, 0);
    }

private:
    int dp[101][2];

    int func(vector<int> &nums, int idx, int visit)
    {
        if (nums.size() == idx)
        {
            return 0;
        }

        if (dp[idx][visit] != -1)
        {
            return dp[idx][visit];
        }

        if (visit)
        {
            dp[idx][visit] = func(nums, idx + 1, 0);
        }
        else
        {
            dp[idx][visit] = max(func(nums, idx + 1, 0), func(nums, idx + 1, 1) + nums[idx]);
        }

        return dp[idx][visit];
    }
};
// @lc code=end
