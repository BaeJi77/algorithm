/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        stack<int> st;

        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
            {
                st.push(1);
            }
            else
            {
                st.push(0);
            }

            n >>= 1;
        }

        uint32_t result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (st.top())
                result += 1 << i;

            st.pop();
        }

        return result;
    }
};
// @lc code=end
