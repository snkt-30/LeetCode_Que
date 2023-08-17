class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        map<int,int>f;
        
        for(auto x:nums)
        {
            f[x]++;
        }
        
        int ind=0;
        
        int ans=0;
        
        for(auto x:f)
        {
            if(x.second==0)
            {
                continue;
            }
            
            if(x.second==1)
            {
                nums[ind]=x.first;
                ind++;
                ans+=1;
            }
            else if(x.second>1)
            {
                nums[ind]=x.first;
                ind++;
                nums[ind]=x.first;
                ind++; 
                ans+=2;
            }
        }
        return ans;
    }
};