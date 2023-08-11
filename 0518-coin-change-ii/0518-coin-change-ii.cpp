class Solution {
    private:
    int cnt=0;
    vector<vector<int>>dp;
    int helper(int ind,int sum,vector<int>&a)
    {
        if(sum==0)
        {
           cnt++;
            return 1;
        }
        if(ind==a.size())
        {
            return 0;
        }
        
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
        
        if(a[ind]>sum)
            return dp[ind][sum]=helper(ind+1,sum,a);
        
        dp[ind][sum]= helper(ind,sum-a[ind],a)+helper(ind+1,sum,a);
        
        return dp[ind][sum];
        
    }
public:
    int change(int amount, vector<int>& a) {
        
        dp.resize(301,vector<int>(5001,-1));
        int ans=helper(0,amount,a);
        
        return ans;
    }
};