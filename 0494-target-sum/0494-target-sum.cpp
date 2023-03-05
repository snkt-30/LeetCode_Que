class Solution {    
    private:
    int helper(vector<int>&a,int curr_sum,int target,int ind)
    {
        if(ind==a.size())
        {
            if(curr_sum==target)
            {
                return 1;
            }
            
            return 0;
        }       
      int take=helper(a,curr_sum+a[ind],target,ind+1);
        
        int not_take=helper(a,curr_sum-a[ind],target,ind+1);
        
        return (take+not_take);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return helper(nums,0,target,0);
    }
};