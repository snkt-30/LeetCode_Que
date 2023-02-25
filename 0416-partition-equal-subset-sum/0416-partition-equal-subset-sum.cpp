#define ll long long int 

class Solution {
    
    private:
    
    bool helper(vector<int>&arr,int sum,int ind,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
           if(sum==0)
               return true;
            
            return false;
        }
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        bool take=0;
        
        if(arr[ind-1]<=sum)
            take=helper(arr,sum-arr[ind-1],ind-1,dp);
        
        bool not_take=helper(arr,sum,ind-1,dp);
        
        return dp[ind][sum]=(take or not_take);
        
    }
public:
    bool canPartition(vector<int>& nums) {
        
        ll sum=0;
        
        ll n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
           if(sum&1)
            return false;
        
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        
        return helper(nums,sum,n,dp);
        
        
        
    }
};