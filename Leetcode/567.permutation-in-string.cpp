/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1Length = s1.size();
        int s2Length = s2.size();

        int map[26] = {0};
        for (int i = 0; i < s1Length; i++)
        {
            map[s1[i] - 'a']++;
        }

        int left = 0;
        for (int i = 0; i < s2Length; i++)
        {
            map[s2[i] - 'a']--;
            if (i >= s1Length)
            {
                map[s2[left] - 'a']++;
                left++;
            }
            if (isZero(map))
            {
                return true;
            }
        }

        return false;
    }

private:
    bool isZero(int map[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (map[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
