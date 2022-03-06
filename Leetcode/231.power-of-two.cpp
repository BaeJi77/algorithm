/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
        {
            return false;
        }

        if (n == 1)
        {
            return true;
        }

        long k = 1;
        for (int i = 0; i < 33; i++)
        {
            if (k == n)
            {
                return true;
            }
            k *= 2;
        }

        return false;
    }
};
// @lc code=end
