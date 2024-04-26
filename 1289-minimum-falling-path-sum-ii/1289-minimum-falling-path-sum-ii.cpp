class Solution {
    
    private:
      int helper(int row,int col, vector<vector<int>>& mat,vector<vector<int>>& dp){
        
        if(row==mat.size())
        {
            return 0;
        }
          
          
          if(dp[row][col]!=INT_MAX)
          {
              return dp[row][col];
          }
          int ans=INT_MAX;

        for(int i=0;i<mat.size();i++)
        {
            int take=INT_MAX;
            if(row==0)
            {
                take=mat[row][i]+helper(row+1,i,mat,dp);
            }
            else if(i!=col)
            {
                take=mat[row][i]+helper(row+1,i,mat,dp);
            }
            ans=min(ans,take);
        }
          
          return dp[row][col]=min(ans,dp[row][col]);
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
         int n= grid.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
        helper(0,0,grid,dp);
        
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};