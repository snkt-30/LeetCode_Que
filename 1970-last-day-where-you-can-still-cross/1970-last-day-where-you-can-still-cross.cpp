class Solution {
    private:
    
    bool isValid(int row, int col,int m,int n)
    {
        return (row>=0 and col>=0 and row<m and col<n);
    }
    
    bool bfs(int day,vector<vector<int>>& a,int m,int n)
    {
         vector<vector<int>> mat(m,vector<int>(n,0));
         // vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<day;i++)
        {
            int row=a[i][0]-1;
            int col=a[i][1]-1;
            
            mat[row][col]=1;
        }
        
        queue<pair<int,int>> bfs;
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        for(int i=0;i<n;i++)
        {
            if(mat[0][i]==0)
            {
                bfs.push(make_pair(0,i));
                mat[0][i]=1;
            }
        }
        
        
        while(!bfs.empty())
        {
            auto x=bfs.front();
                bfs.pop();
                
                int row=x.first;
                int col=x.second;
                
                // mat[row][col]=true;
                // mat[row][col]=1;
                for(int del=0;del<4;del++)
                {
                    int nrow=row+dx[del];
                    int ncol=col+dy[del];
                    
                    if(isValid(nrow,ncol,m,n) and mat[nrow][ncol]==0)
                    {
                        bfs.push(make_pair(nrow,ncol));
                        mat[nrow][ncol]=1;
                        
                        if(nrow==m-1)
                            return true;
                        
                    }
                }
        }
        
        return false;
    }
    
public:
    int latestDayToCross(int m, int n, vector<vector<int>>& a) {
        
        int l=1,r=a.size();
        
        int ans=0;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(bfs(mid,a,m,n)==true)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        
        return ans;
    }
};