/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int> > permute(vector<int> &nums)
    {
        bool visited[10] = {0};
        vector<int> vt;

        func(nums, visited, vt);

        return result;
    }

private:
    vector<vector<int> > result;

    void func(vector<int> &nums, bool visited[], vector<int> vt)
    {
        if (nums.size() == vt.size())
        {
            result.push_back(vt);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            vt.push_back(nums[i]);
            visited[i] = true;
            func(nums, visited, vt);
            visited[i] = false;
            vt.pop_back();
        }
    }
};
// @lc code=end
