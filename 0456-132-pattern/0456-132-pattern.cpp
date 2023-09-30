class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        
        int mn=nums[0];
        
        int n=nums.size();
        
        map<int,int>mp;
        
        for(int i=1;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=1;i<n;i++)
        {
            mp[nums[i]]--;
            
            if(mp[nums[i]]==0)
            {
                mp.erase(nums[i]);
            }
            
            auto it=mp.upper_bound(mn);
            
            if(it!=mp.end())
            {
                int ub=(*it).first;
                
                if(nums[i]>mn and nums[i]>ub and mn<ub)
                {
                    return true;
                }
            }
            
            mn=min(mn,nums[i]);
 
        }

        return false;
    }
};