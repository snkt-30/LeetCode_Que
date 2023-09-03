class Solution {
    
    int ans(int row,int col,int dp[][101])
    {
        
        if(row<0 or col<0)
            return 0;
        if(row==0 and  col==0)
        {
            return 1;
        }
        
        if(dp[row][col]!=-1)
            return dp[row][col];
          int up=ans(row-1,col,dp);
        
           int left=ans(row,col-1,dp);
        
       return  dp[row][col]=up+left;
        
        
    }
public:
    int uniquePaths(int m, int n) {
        
        
        int dp[101][101];
        
        memset(dp,-1,sizeof(dp));
        
        return ans(m-1,n-1,dp);
    }
};