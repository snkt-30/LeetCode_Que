class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up_left=INT_MAX;
                int up=dp[i-1][j];
                int up_right=INT_MAX;
                if(j>0)
                {
                   up_left=dp[i-1][j-1]; 
                }
                if(j<m-1)
                {
                    up_right=dp[i-1][j+1];
                }
                dp[i][j]+=matrix[i][j]+min({up_left,up,up_right});
                
            }
        }
        
        int res=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            res=min(res,dp[n-1][i]);
        }
        
        return res;
    }
    
    
    
};