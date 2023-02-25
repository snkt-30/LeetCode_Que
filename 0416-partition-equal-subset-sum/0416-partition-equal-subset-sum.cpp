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
        
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=false;
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool take=0;
                
                if(nums[i-1]<=j)
                {
                    take=dp[i-1][j-nums[i-1]];
                }
                
                bool not_take=dp[i-1][j];
                
                dp[i][j]=(take or not_take);
            }
        }
        
      return dp[n][sum];
        
        
        
    }
};