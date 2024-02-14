class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        long long int maxi=LONG_MIN;
        long long int sum=0;
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        for(int i=0;i<nums.size();i++)
        {    
            sum+=nums[i];
            
            maxi=max(maxi,sum);
            
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
  
    }
};