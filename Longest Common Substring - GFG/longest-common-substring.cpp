//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    private:
    
    int lcs(string a,string b,int n,int m)
    {
       if(n==0 or m==0)
        {
            return 0;
        }
        
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        
        int match;
        
        if(a[n-1]==b[m-1])
        {
            match=1+lcs(a,b,n-1,m-1);
        }
        else
        {
            match=0;
        }
        
        lcs(a,b,n-1,m);
        lcs(a,b,n,m-1);
        
        return dp[n][m]=match;
        
    }
    public:
    
    int dp[1001][1001];
    
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
        
        memset(dp,-1,sizeof(dp));
        
        // int ans=0;
        
        //  lcs(a,b,n,m);
         
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         ans=max(ans,dp[i][j]);
        //     }
        // }
        
        // return ans;
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        
        int mx=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
                
                mx=max(mx,dp[i][j]);
            }
        }
        
        return mx;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends