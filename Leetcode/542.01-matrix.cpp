/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
    {
        N = mat.size();
        M = mat[0].size();

        vector<vector<int> > result;
        for (int i = 0; i < mat.size(); i++)
        {
            vector<int> arr(M, 0);
            result.push_back(arr);
        }

        queue<pair<int, int> > q;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }
                if (mat[i][j] == 0)
                    result[i][j] = 0;
                else
                    result[i][j] = MAX;
            }
        }

        int distance = 1;
        while (int s = q.size())
        {
            while (s--)
            {
                int y = q.front().first;
                int x = q.front().second;

                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int yy = y + dy[i];
                    int xx = x + dx[i];

                    if (yy < 0 || yy >= N || xx < 0 || xx >= M)
                        continue;
                    if (result[yy][xx] != MAX)
                        continue;
                    if (mat[yy][xx] == 0)
                        continue;

                    result[yy][xx] = distance;
                    q.push(make_pair(yy, xx));
                }
            }
            distance++;
        }

        return result;
    }

private:
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    int MAX = 10000000;
    int N, M;
};
// @lc code=end
