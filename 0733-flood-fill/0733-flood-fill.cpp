class Solution
{

    private:

        bool isValid(int nrow, int ncol, int row, int col)
        {
            return (nrow >= 0 and nrow < row and ncol >= 0 and ncol < col);
        }
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {

            int dx[4] = { -1,
                1,
                0,
                0
            };
            int dy[4] = { 0,
                0,
                -1,
                1
            };

            int n = image.size();
            int m = image[0].size();

            queue<pair<int, pair<int, int>>> q;

            int val = image[sr][sc];

            q.push(make_pair(val, make_pair(sr, sc)));

            while (!q.empty())
            {
                int val = q.front().first;
                int r = q.front().second.first;
                int c = q.front().second.second;
                q.pop();
                image[r][c] = color;

                for (int del = 0; del < 4; del++)
                {
                    int nrow = r + dx[del];
                    int ncol = c + dy[del];

                    if (isValid(nrow, ncol, n, m) and image[nrow][ncol] == val and image[nrow][ncol]!=color)
                    {
                        q.push(make_pair(image[nrow][ncol], make_pair(nrow, ncol)));
                       
                    }
                }
            }

            return image;
        }
};