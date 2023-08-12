class Solution {
    
    int path(int row,int col,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(row<0 or col<0)
            return 0;
        
        if(a[row][col]==1)
            return 0;
        
        if(row==0 and col==0)
            return 1;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int le=path(row-1,col,a,dp);
        int rh=path(row,col-1,a,dp);
        
     return dp[row][col]=le+rh;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        
        int n=a.size();
        int m=a[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return path(n-1,m-1,a,dp);
        
//         queue<pair<int,int>> bfs;
        
        
//         // cout<<n<<" "<<m<<endl;
//         if(n==1 and m==1 and a[0][0]==1)
//             return 0;
        
//          if(n==1 and m==1 and a[0][0]==0)
//             return 1; 
        
        
//         if(a[0][0]==1 or a[n-1][m-1]==1)
//             return 0;
        
//         int ans=0;
        
//         vector<vector<int>> vis(n,vector<int>(m,0));
        
//         bfs.push({0,0});
        
//         while(!bfs.empty())
//         {
//             auto x=bfs.front();
//               bfs.pop();
            
//             int row=x.first;
//             int col=x.second;
            
//             if(row==n-1 and col==m-1)
//             {
//                 ans++;
//             }
            
//             cout<<row<<" "<<col<<endl;
            
//             vis[row][col]=1;
            
//             if(isValid(row,col+1,n,m) and a[row][col+1]!=1 and !vis[row][col+1])
//             {
//                 bfs.push({row,col+1});
//             }
            
//             if(isValid(row+1,col,n,m) and a[row+1][col]!=1 and !vis[row+1][col])
//             {
//                 bfs.push({row+1,col});
//             }
//         }
        
//         return ans;
    }
};