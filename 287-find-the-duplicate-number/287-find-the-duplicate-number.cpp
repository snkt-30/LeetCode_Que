class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> ans;
        // int res;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
        }
        
        for(auto x:ans)
        {
            if(x.second>1)
            {
               
                return (x.first);
                
            }
        }
        
        return -1;
    }
};