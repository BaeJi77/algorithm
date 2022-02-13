/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> strs = split(s, ' ');
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];

            int left = 0;
            int right = s.size() - 1;

            while (left < right)
            {
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }

            strs[i] = s;
        }

        string result = "";
        for (int i = 0; i < strs.size(); i++)
        {
            result.append(strs[i]);

            if (i != strs.size() - 1)
            {
                result.append(" ");
            }
        }

        return result;
    }

    vector<string> split(string input, char delimiter)
    {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter))
        {
            answer.push_back(temp);
        }

        return answer;
    }
};
// @lc code=end
