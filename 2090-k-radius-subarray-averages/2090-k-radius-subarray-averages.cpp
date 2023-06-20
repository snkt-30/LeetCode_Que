class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int lo=0,hi=0;
        
        int n=nums.size();
        
        vector<int> ans(n,-1);
        
        int sz=2*k+1;
        
        long long sum=0;
        
        while(hi<n)
        {
            sum+=nums[hi];
            
            if((hi-lo+1)==sz)
            {
                ans[hi-k]=sum/sz;
                sum-=nums[lo];
                lo++;
            }
            else
            {
                ans[hi]=-1;
            }
            
            hi++;
        }
        
        return ans;
    }
};