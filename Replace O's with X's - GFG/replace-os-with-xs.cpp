//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool isValid(int row,int col, int n,int m)
    {
        return (row>=0 and col>=0 and row<n and col<m);
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> bfs;
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')
            {
                bfs.push({i,0});
            }
            
            if(mat[i][m-1]=='O')
            {
                bfs.push({i,m-1});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O')
            {
                bfs.push({0,i});
            }
            
            if(mat[n-1][i]=='O')
            {
                bfs.push({n-1,i});
            }
        }
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        while(!bfs.empty())
        {
            auto x=bfs.front();
            bfs.pop();
            
            int row=x.first;
            int col=x.second;
            
            vis[row][col]=1;
            
            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(isValid(nrow,ncol,n,m) and !vis[nrow][ncol] and mat[nrow][ncol]=='O')
                {
                    bfs.push({nrow,ncol});
                }
            }
        }
        
        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    ans[i][j]='X';
                }
                else
                {
                    ans[i][j]='O';
                }
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends