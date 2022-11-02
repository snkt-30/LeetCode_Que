//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    
    void dfs(int row,int col, vector<vector<char>>&mat, vector<vector<int>>&vis)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        vis[row][col]=1;
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and mat[nrow][ncol]=='O' and vis[nrow][ncol]==0)
            {
                dfs(nrow,ncol,mat,vis);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>>&mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] and mat[0][i]=='O')
              dfs(0,i,mat,vis);
              
            if(!vis[n-1][i] and mat[n-1][i]=='O')
               dfs(n-1,i,mat,vis);
        }
        
         for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O' and !vis[i][0])
              dfs(i,0,mat,vis);
              
            if(mat[i][m-1]=='O' and !vis[i][m-1])
               dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O' and !vis[i][j])
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
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