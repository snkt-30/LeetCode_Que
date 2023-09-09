class Solution {
    
    private:
    
    vector<int>dp;
    
    int helper(int sum,vector<int>&a,int t)
    {
        if(sum>t)
        {
            return 0;
        }
        
//         if(ind>=a.size())
//             return 0;
        
        if(sum==t)
        {
            return 1;
        }
        
        if(dp[sum]!=-1)
        {
           return dp[sum];
        }
        int res=0;
        
        for(int i=0;i<a.size();i++)
        {
            if(sum+a[i]<=t){
            res+=helper(sum+a[i],a,t);
            }
        }
        
        return dp[sum]=res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(1001,-1);
        
        // memset(dp,-1,sizeof(dp));
        
        return helper(0,nums,target);
    }
};