class Solution {
    
    private:
    
    vector<vector<int>>dp;
    
    int helper(int ind,int sum,vector<int>&a,int t)
    {
        if(sum>t)
        {
            return 0;
        }
        
        if(ind>=a.size())
            return 0;
        
        if(sum==t)
        {
            return 1;
        }
        
        if(dp[ind][sum]!=-1)
        {
           return dp[ind][sum];
        }
        int res=0;
        
        for(int i=0;i<a.size();i++)
        {
            res+=helper(i,sum+a[i],a,t);
        }
        
        return dp[ind][sum]=res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(500,vector<int>(200010,-1));
        
        // memset(dp,-1,sizeof(dp));
        
        return helper(0,0,nums,target);
    }
};