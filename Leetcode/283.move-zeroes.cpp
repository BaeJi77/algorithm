/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zeroPoint = 0;
        int valuePoint = 0;
        while (zeroPoint < nums.size() && valuePoint < nums.size())
        {
            printf("zero=%d value=%d nums[zero]=%d nums[value]=%d\n", zeroPoint, valuePoint, nums[zeroPoint], nums[valuePoint]);
            if (nums[zeroPoint] == 0)
            {
                if (nums[valuePoint] == 0)
                {
                    valuePoint++;
                }
                else
                {
                    nums[zeroPoint] = nums[valuePoint];
                    nums[valuePoint] = 0;

                    zeroPoint++;
                    valuePoint++;
                }
            }
            else
            {
                zeroPoint++;
                if (zeroPoint >= valuePoint)
                {
                    valuePoint = zeroPoint;
                }
            }
        }
    }
};
// @lc code=end
