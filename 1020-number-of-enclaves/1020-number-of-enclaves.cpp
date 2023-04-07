
// #define mk make_pair
// class Solution
// {

//     private:

//         bool isValid(int row, int col, int r, int c)
//         {
//             return (row >= 0 and row < r and col >= 0 and col < c);
//         }

//     int bfs(int row, int col, vector<vector < int>> &a, vector< vector< int>> &vis)
//     {
//         queue<pair<int,int>> bfs;
        
//         int n=a.size();
//         int m=a[0].size();
        
//         bfs.push(mk(row,col));
        
//         int dx[4]={-1,1,0,0};
//         int dy[4]={0,0,-1,1};
        
        
//         int cnt=0;
        
//         bool flag=true;
        
//         while(!bfs.empty())
//         {
//             int row=bfs.front().first;
//             int col=bfs.front().second;
            
//             vis[row][col]=true;
            
//             cnt++;
//             if(row==0 or row==n-1 or col==0 or col==m-1)
//             {
//                 flag=false; 
//             }     
//             bfs.pop();
            
//             for(int i=0;i<4;i++)
//             {
//                 int nrow=row+dx[i];
//                 int ncol=col+dy[i];
                
//                 if(isValid(nrow,ncol,n,m) and !vis[nrow][ncol] and a[nrow][ncol]==1)
//                 {
//                     vis[nrow][ncol]=true;
//                     bfs.push(mk(nrow,ncol));
//                 }
//             }
//         }
        
//         if(!flag)return 0;
        
//         return cnt;
//     }
    
    
//     public:
//         int numEnclaves(vector<vector < int>> &a)
//         {

//             int n = a.size();
//             int m = a[0].size();

//             vector<vector < int>> vis(n, vector<int> (m, 0));

//             int Enc = 0;

//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (a[i][j] == 1 and !vis[i][j])
//                     {
//                         Enc += bfs(i, j, a, vis);
//                     }
//                 }
//             }
            
//             return Enc;
//         }
// };

class Solution {
public:
    void bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;

        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

        while (!q.empty()) {
            x = q.front().first;   // row nnumber
            y = q.front().second;  // column number
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + dirx[i];
                int c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n) {
                    continue;
                } else if (grid[r][c] == 1 && !visit[r][c]) {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            // First column.
            if (grid[i][0] == 1 && !visit[i][0]) {
                bfs(i, 0, m, n, grid, visit);
            }
            // Last column.
            if (grid[i][n - 1] == 1 && !visit[i][n - 1]) {
                bfs(i, n - 1, m, n, grid, visit);
            }
        }

        for (int i = 0; i < n; ++i) {
            // First row.
            if (grid[0][i] == 1 && !visit[0][i]) {
                bfs(0, i, m, n, grid, visit);
            }
            // Last row.
            if (grid[m - 1][i] == 1 && !visit[m - 1][i]) {
                bfs(m - 1, i, m, n, grid, visit);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};