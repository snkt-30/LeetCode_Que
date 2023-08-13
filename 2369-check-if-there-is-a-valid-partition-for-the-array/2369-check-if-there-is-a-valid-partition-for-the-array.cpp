class Solution {
public:
    int solve(int idx, vector<int> &nums, vector<int> &dp){
        if(idx < 0) return 1;
        if(dp[idx] != -1) return dp[idx];
        int ans = 0;
        if(idx > 0 && nums[idx] == nums[idx-1]) 
            ans = ans | solve(idx-2, nums, dp);
        if(idx > 1 && nums[idx] == nums[idx-1] && nums[idx-1] == nums[idx-2]) 
            ans = ans | solve(idx - 3, nums, dp);
        if(idx > 1 && (nums[idx] - nums[idx-1] == 1) && (nums[idx-1] - nums[idx-2] == 1)) 
            ans = ans | solve(idx - 3, nums, dp);

        return dp[idx] = ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return solve(n-1, nums, dp);
    }
};