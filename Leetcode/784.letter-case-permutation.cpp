/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                visited[i][j] = false;
            }
        }

        func(s, "", 0);

        return result;
    }

private:
    vector<string> result;
    bool visited[13][2];

    void func(string s, string now, int idx)
    {
        if (s.size() == now.size())
        {
            result.push_back(now);
            return;
        }

        int num = charToNum(s[idx]);
        if (num == -1)
        {
            now.push_back(s[idx]);
            func(s, now, idx + 1);
            now.pop_back();
        }
        else
        {
            now.push_back(toupper(s[idx]));
            func(s, now, idx + 1);
            now.pop_back();

            now.push_back(tolower(s[idx]));
            func(s, now, idx + 1);
            now.pop_back();
        }
    }

    int charToNum(char c)
    {
        if ('a' <= c && c <= 'z')
        {
            return 0;
        }
        if ('A' <= c && c <= 'Z')
        {
            return 1;
        }
        return -1;
    }
};
// @lc code=end
