/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<int> first;

        func(n, k, first, 1);

        return result;
    }

    void func(int n, int k, vector<int> vt, int num)
    {
        if (vt.size() == k)
        {
            result.push_back(vt);
            return;
        }

        for (int i = num; i <= n; i++)
        {
            vt.push_back(i);
            func(n, k, vt, i + 1);
            vt.pop_back();
        }
    }

private:
    vector<vector<int> > result;
};
// @lc code=end
