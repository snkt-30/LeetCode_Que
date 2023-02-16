class Solution {
    
    private:
    
    bool isValid(int nrow,int ncol,int row,int col)
    {
        return (nrow>=0 and nrow<row and ncol>=0 and ncol<col);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        
        q.push(make_pair(sr,sc));
        
        vis[sr][sc]=1;
       
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            int val=image[r][c];
            
            for(int del=0;del<4;del++)
            {
                int nrow=r+dx[del];
                int ncol=c+dy[del];
                
                if(isValid(nrow,ncol,n,m) and image[nrow][ncol]== val and !vis[nrow][ncol])
                {
                    q.push(make_pair(nrow,ncol));
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                {
                    image[i][j]=color;
                }
            }
        }
        
        return image;
        
        
        
    }
};