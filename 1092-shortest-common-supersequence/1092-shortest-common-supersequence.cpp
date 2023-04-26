class Solution {
    
public:
    string shortestCommonSupersequence(string x, string y) {
        
        int n=x.length();
        int m=y.length();
        
        int dp[n+1][m+1];
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    if(x[i-1]==y[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int i=n,j=m;
        
        string s="";
        
        while(i>0 and j>0)
        {
            if(x[i-1]==y[j-1])
            {
                s+=x[i-1];
                i--,j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    s+=x[i-1];
                    i--;
                }
                else
                {
                    s+=y[j-1];
                    j--;
                }
            }
        }
        
        
        while(i>0)
        {
            s+=x[i-1];
            i--;
        }
        
        while(j>0)
        {
            s+=y[j-1];
            j--;
        }
        reverse(s.begin(),s.end());
        
        
        
        return s;
        
    
        
    }
};