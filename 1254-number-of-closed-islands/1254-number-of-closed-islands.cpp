
#define mk make_pair
class Solution
{

    private:

        bool check(int row, int col, int n, int m)
        {
            return (row >= 0 and row < n and col >= 0 and col < m);
        }
    
    public:
        int closedIsland(vector<vector < int>> &a)
        {

            int n = a.size();
            int m = a[0].size();

            vector<vector < int>> vis(n, vector<int> (m, 0));

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

            queue<pair<int, int>> bfs;
            for (int i = 0; i < n; i++)
            {
                if (a[i][0] == 0)
                {
                    bfs.push(mk(i, 0));
                }

                if (a[i][m - 1] == 0)
                {
                    bfs.push(mk(i, m - 1));
                }
            }

            for (int i = 0; i < m; i++)
            {
                if (a[0][i] == 0)
                {
                    bfs.push(mk(0, i));
                }

                if (a[n - 1][i] == 0)
                {
                    bfs.push(mk(n - 1, i));
                }
            }

            while (!bfs.empty())
            {
                int row = bfs.front().first;
                int col = bfs.front().second;

                bfs.pop();

                vis[row][col] = true;
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];

                if (check(nrow, ncol, n, m) and vis[nrow][ncol] == false and a[nrow][ncol] ==0)
                    {
                        vis[nrow][ncol] = true;
                        bfs.push(mk(nrow, ncol));
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << vis[i][j] << " ";
                }
                cout << endl;
            }

            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 0 and vis[i][j] == false)
                    {
                        cnt++;

                        cout << i << " " << j << endl;
                        bfs.push(mk(i, j));

                        while (!bfs.empty())
                        {
                            int row = bfs.front().first;
                            int col = bfs.front().second;

                            bfs.pop();

                            vis[row][col] = true;

                            for (int i = 0; i < 4; i++)
                            {
                                int nrow = row + dx[i];
                                int ncol = col + dy[i];

                        if (check(nrow, ncol, n, m) and a[nrow][ncol] == 0 and!vis[nrow][ncol])
                                {
                                    vis[nrow][ncol] = true;
                                    bfs.push(mk(nrow, ncol));
                                }
                            }
                        }
                    }
                }
            }

            return cnt;

            return 0;
        }
};