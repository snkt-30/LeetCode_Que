class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        // int res;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
            if(ans[nums[i]]>1)
                return nums[i];
        }
       
        
        return -1;
    }
};