class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        map<int,int>mp;
        nums[0]=(k+nums[0]%k)%k;
        
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
            nums[i]=(k+nums[i]%k)%k;
        }
        
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
                ans+=mp[nums[i]];
            
            mp[nums[i]]++;
        }
        
        return ans;
    }
};