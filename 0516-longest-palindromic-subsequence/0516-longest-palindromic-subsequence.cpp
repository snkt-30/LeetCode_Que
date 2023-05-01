class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        string b=s;
        reverse(b.begin(),b.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(s[i-1]==b[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[n][n];
    }
};