class Solution {
    
    private:
    
    long long helper(int ind,vector<vector<int>>& a, vector<long long>&dp,int n)
    {
        if(ind>=n)
        {
            return 0;
        }
        
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
         
        long long dis=a[ind][1];
        long long take=a[ind][0]+helper(ind+dis+1,a,dp,n);
        
        long long not_take=0+helper(ind+1,a,dp,n);
        
        dp[ind]=max(take,not_take);
        
        return dp[ind];
        
        
    }
public:
    long long mostPoints(vector<vector<int>>& a) {
        
        int n=a.size();
        vector<long long > dp(n);
        
        dp[n-1]=a[n-1][0];
        
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = a[i][0];
            int skip = a[i][1];
            if (i + skip + 1 < n) {
                dp[i] += dp[i + skip + 1];
            }
            
            // dp[i] = max(solve it, skip it)
            dp[i] = max(dp[i], dp[i + 1]);
        }
        
        return dp[0];
        
        
        // return helper(0,a,dp,n);
    }
};