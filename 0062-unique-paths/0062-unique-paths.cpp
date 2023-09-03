class Solution {
    
//     int ans(int row,int col,int dp[][101])
//     {
        
//         if(row<0 or col<0)
//             return 0;
//         if(row==0 and  col==0)
//         {
//             return 1;
//         }
        
//         if(dp[row][col]!=-1)
//             return dp[row][col];
//           int up=ans(row-1,col,dp);
        
//            int left=ans(row,col-1,dp);
        
//        return  dp[row][col]=up+left;
        
        
//     }
public:
    int uniquePaths(int m, int n) {
        
        
        int dp[101][101];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                
            }
    }
        
        return dp[m-1][n-1];
        
        // return ans(m-1,n-1,dp);
    }
};