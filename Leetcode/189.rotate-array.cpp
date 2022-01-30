/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> result(nums.size());

        k %= nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            result[i] = nums[(nums.size() - k + i) % nums.size()];
        }

        nums = result;
    }
};
// @lc code=end
