class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int>ans;
        
        int nn=n;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[nn+i]);
        }
        
        return ans;
    }
};