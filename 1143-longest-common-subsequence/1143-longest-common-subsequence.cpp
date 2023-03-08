class Solution
{

//     private:

//         int lcs(string x, string y, int n, int m, vector<vector < int>> &dp)
//         {
//             if (n == 0 or m == 0)
//             {
//                 return 0;
//             }

//             if (dp[n][m] != -1)
//             {
//                 return dp[n][m];
//             }

//             int ans = 0;
//             if (x[n - 1] == y[m - 1])
//             {
//                 ans = 1 + lcs(x, y, n - 1, m - 1, dp);
//             }
//             else
//             {
//                 ans = max(lcs(x, y, n - 1, m, dp), lcs(x, y, n, m - 1, dp));
//             }

//             return dp[n][m] = ans;
//         }
    public:
        int longestCommonSubsequence(string x, string y)
        {

            int n = x.length();
            int m = y.length();

            vector<vector < int>> dp(n + 1, vector<int> (m + 1));
            
            for(int i=0;i<=n;i++)
            {
                dp[i][0]=0;
            }
            
            for(int i=0;i<=m;i++)
            {
                dp[0][i]=0;
            }
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    int ans=0;
                    
                    if(x[i-1]==y[j-1])
                    {
                        ans=1+dp[i-1][j-1];
                    }
                    else
                    {
                        ans=max(dp[i-1][j],dp[i][j-1]);
                    }
                    
                    dp[i][j]=ans;
                }
            }
            
            return dp[n][m];
            
           
        }
};