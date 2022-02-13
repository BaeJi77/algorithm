/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = false;
            }
        }

        int maxCount = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (c[i][j] || grid[i][j] == 0)
                    continue;

                maxCount = max(maxCount, func(grid, i, j));
            }
        }

        return maxCount;
    }

private:
    bool c[51][51];
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    int m;
    int n;

    int func(vector<vector<int> > &grid, int y, int x)
    {
        int count = 0;
        c[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (m <= yy || yy < 0 || n <= xx || xx < 0)
            {
                continue;
            }

            if (c[yy][xx] || grid[yy][xx] == 0)
            {
                continue;
            }

            count += func(grid, yy, xx);
        }

        return count + 1;
    }
};
// @lc code=end
