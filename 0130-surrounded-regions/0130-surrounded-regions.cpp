class Solution {
    
    private:
    
      bool isValid(int nrow,int ncol,int row,int col)
      {
          return (nrow>=0 and nrow<row and ncol>=0 and ncol<col);
      }
public:
    void solve(vector<vector<char>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        
        queue<pair<int,int>> bfs;
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O'){
                bfs.push({i,0});
                vis[i][0]=1;
            }
            
            if(mat[i][m-1]=='O'){
                bfs.push({i,m-1});
                vis[i][m-1]=1;
            }
            
        }
        
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O'){
                vis[0][i]=1;
                bfs.push({0,i});
            }
            
            if(mat[n-1][i]=='O'){
                bfs.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        
        
        while(!bfs.empty())
        {
            int row=bfs.front().first;
            int col=bfs.front().second;
            
            bfs.pop();
            
            for(int del=0;del<4;del++)
            {
                int nrow=row+dx[del];
                int ncol=col+dy[del];
                
                if(isValid(nrow,ncol,n,m) and mat[nrow][ncol]=='O' and !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    bfs.push(make_pair(nrow,ncol));
                }
            }
     
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                {
                    mat[i][j]='O';
                }
                else
                {
                    mat[i][j]='X';
                }
            }
        }
        
    }
};