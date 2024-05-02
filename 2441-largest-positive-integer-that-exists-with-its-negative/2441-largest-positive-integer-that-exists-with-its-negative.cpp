class Solution {
public:
    int findMaxK(vector<int>& nums) {
      
        sort(nums.begin(),nums.end());
        
        unordered_map<int,bool>mp;
        
        for(int i=1;i<=1000;i++)
        {
            mp[i]=false;
            mp[i*(-1)]=false;
        }
        
        
        for(auto x:nums){
            mp[x]=true;
        }
        
        int ans=-1;
        for(int i=0;(i<nums.size() and nums[i]<0);i++)
        {
            int val = nums[i]*(-1);
            if(mp[val]==true)
            {
                ans=val;
                break;
            }
        }
        
        return ans;
        
    }
};