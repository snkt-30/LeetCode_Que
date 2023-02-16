class Solution
{
    
    private:
    
    bool isValid(int nrow,int ncol,int row,int col)
    {
        return (nrow>=0 and nrow<row and ncol>=0 and ncol<col);
    }
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {

            queue<pair<int, pair<int, int>>> bfs;

            int n = mat.size();
            int m = mat[0].size();

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

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 0)
                        bfs.push(make_pair(0, make_pair(i, j)));
                }
            }

            vector<vector < int>> vis(n, vector<int> (m, 0));

            while (!bfs.empty())
            {
                int dist = bfs.front().first;
                int row = bfs.front().second.first;
                int col = bfs.front().second.second;

                bfs.pop();

                for (int del = 0; del < 4; del++)
                {
                    int nrow = row + dx[del];
                    int ncol = col + dy[del];

                    if (isValid(nrow, ncol, n, m) and!vis[nrow][ncol] and mat[nrow][ncol] != 0)
                    {
                        mat[nrow][ncol] = dist + 1;
                        vis[nrow][ncol] = 1;

                        bfs.push(make_pair(dist + 1, make_pair(nrow, ncol)));
                    }
                }
            }
            
            return mat;
        }
};