class Solution {
public:
    
    int max_rob(int ind,vector<int>&nums,int n,int dp[])
    {
        if(ind==0)
        {
            return nums[ind];
        }
        if(ind<0)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
       int take=nums[ind]+max_rob(ind-2,nums,n,dp);
        
        int not_take=0+max_rob(ind-1,nums,n,dp);
        
        return dp[ind]=max(take,not_take);
        
        // int no_take=0+max_rob(ind-1,nums,n);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        return max_rob(n-1,nums,n,dp);
    }
};