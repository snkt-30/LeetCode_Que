class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // sort(nums.begin(),nums.end());
        
        unordered_map<int,int>mp;
        int lo=0;
        int hi=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])==mp.end())
            {
                mp[nums[i]]=i;
            }
            else if(mp.find(target-nums[i])!=mp.end())
                   {
                       lo=i;
                       hi=mp[target-nums[i]];
                       break;
                   }
        }
                   vector<int> ans;
                   ans.push_back(lo);
                   ans.push_back(hi);
                   return ans;
    }
};