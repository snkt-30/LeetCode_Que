class Solution {    
//     private:
//     int helper(vector<int>&a,int curr_sum,int target,int ind)
//     {
//         if(ind==a.size())
//         {
//             if(curr_sum==target)
//             {
//                 return 1;
//             }
            
//             return 0;
//         }       
//       int take=helper(a,curr_sum+a[ind],target,ind+1);
        
//         int not_take=helper(a,curr_sum-a[ind],target,ind+1);
        
//         return (take+not_take);
//     }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

           long long int sum=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(target<0)
        {
            target=target*(-1);
        }
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int take=0;
                
                if(nums[i-1]<=j)
                {
                    take=dp[i-1][j-nums[i-1]];
                }
                
                int not_take=dp[i-1][j];
                
                dp[i][j]=(take+not_take);
            }
        }
        int ans=0;
        for(int i=0;i<=(sum/2);i++)
        {
            if(dp[n][i]!=0)
            {
                int val=sum-(2*i);
                
                if(val==target)
                    ans+=dp[n][i];
            }
        }        
        return ans;             
    }
};