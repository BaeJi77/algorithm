/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int> > &grid)
    {
        int N = grid.size();
        int M = grid[0].size();
        bool visited[11][11] = {0};

        queue<pair<int, int> > q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                visited[i][j] = false;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        // printf("%d\n", q.size());

        int count = 0;
        while (int s = q.size())
        {
            while (s--)
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                visited[y][x] = true;
                for (int i = 0; i < 4; i++)
                {
                    int yy = y + dy[i];
                    int xx = x + dx[i];

                    if (yy < 0 || yy >= N || xx < 0 || xx >= M)
                        continue;

                    // printf("%d %d %d %d\n", yy, xx, visited[yy][xx], grid[yy][xx]);
                    if (visited[yy][xx])
                        continue;
                    if (grid[yy][xx] != 1)
                        continue;

                    grid[yy][xx] = 2;
                    q.push(make_pair(yy, xx));
                }
            }

            count++;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return count == 0 ? 0 : count - 1;
    }

private:
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
};
// @lc code=end
