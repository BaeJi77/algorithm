/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    // numbers 오름차순 정렬.
    // 2개의 value를 더해서 target 값이 되는 해당 값의 index 2개.
    // 반드시 하나의 경우는 존재함. 중복된 숫자는 사용하지 못함.
    // 1번 인덱싱임.
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;

        int left = 0;
        int right = numbers.size() - 1;
        while (numbers[left] + numbers[right] != target)
        {
            int sum = numbers[left] + numbers[right];
            if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        result.push_back(left + 1);
        result.push_back(right + 1);
        return result;
    }
};
// @lc code=end
