class Solution {
    
    private:
    static bool isvalid(int row,int col,int n,int m)
    {
        return (row>=0 and row<n and col>=0 and col<m);
    }
    
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int dx[],int dy[])
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        
        for(int del=0;del<4;del++)
        {
            int nrow=row+dx[del];
            int ncol=col+dy[del];
            
            if(isvalid(nrow,ncol,n,m) and !vis[nrow][ncol] and grid[nrow][ncol]=='1')
            {
                dfs(nrow,ncol,grid,vis,dx,dy);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
                  
        int cnt=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid,vis,dx,dy);
                }
            }
        }
        
        return cnt;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    cnt++;
                    queue<pair<int,int>> bfs;
                    
                    bfs.push(make_pair(i,j));
                    vis[i][j]=1;
                    
                    while(!bfs.empty())
                    {
                        pair<int,int> node=bfs.front();
                        bfs.pop();
                        
                        int row=node.first;
                        int col=node.second;
                        
                        for(int del=0;del<4;del++)
                        {
                            int nrow=row+dx[del];
                            int ncol=col+dy[del];
                            
                            if(isvalid(nrow,ncol,n,m) and !vis[nrow][ncol] and grid[nrow][ncol]==
                              '1')
                            {
                                vis[nrow][ncol]=1;
                                bfs.push(make_pair(nrow,ncol));
                                
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
        
    }
};