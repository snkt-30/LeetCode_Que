#define ll long long int

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
                ll n=nums.size();
        
        nums[0]=(k+nums[0]%k)%k;
        
        
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
            
            nums[i]=(k+nums[i]%k)%k;
        }
        

        ll ans=0;
        ll sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
          if(mp.count(nums[i]))
              ans+=mp[nums[i]];
            
            mp[nums[i]]++;
        }
        
        return ans;
    }
};