/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        for (int i = 0; i < 51; i++)
        {
            for (int j = 0; j < 51; j++)
            {
                c[i][j] = false;
            }
        }

        int m = image.size();
        int n = image[0].size();

        func(image, image[sr][sc], m, n, sr, sc, newColor);

        vector<vector<int> > temp;
        temp.resize(image.size());

        for (int i = 0; i < image.size(); i++)
        {
            vector<int> row;
            for (int j = 0; j < image[i].size(); j++)
            {

                row.push_back(image[i][j]);
            }
            printf("\n");
            temp[i] = row;
        }

        return temp;
    }

private:
    int yy[4] = {1, -1, 0, 0};
    int xx[4] = {0, 0, 1, -1};
    bool c[51][51];

    void func(vector<vector<int> > &image, int targetColor, int ly, int lx, int dy, int dx, int color)
    {
        image[dy][dx] = color;
        c[dy][dx] = true;
        for (int i = 0; i < 4; i++)
        {
            int y = dy + yy[i];
            int x = dx + xx[i];

            if (ly <= y || y < 0 || lx <= x || x < 0 || c[y][x])
                continue;

            if (image[y][x] == targetColor)
            {
                func(image, targetColor, ly, lx, y, x, color);
            }
        }
    }
};
// @lc code=end
