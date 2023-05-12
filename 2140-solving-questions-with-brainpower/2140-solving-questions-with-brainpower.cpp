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
        vector<long long > dp(n,-1);
        
        
        return helper(0,a,dp,n);
    }
};