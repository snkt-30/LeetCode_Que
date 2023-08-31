class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        const int inf=1e9;
        
        vector<int>dp(n+1,inf);
        
        
        dp[0]=0;
        
        for(int i=0;i<=n;i++){
            
            int st=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            
            for(int j=st;j<=end;j++)
            {
                dp[end]=min(dp[end],dp[j]+1);
            }
        }
        
        return dp[n]==inf?-1:dp[n];
    }
};