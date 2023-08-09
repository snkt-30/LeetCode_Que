class Solution {
    
    int helper(vector<int>&a,int mn)
    {
        int ind=0,cnt=0;
        
        
        while(ind<a.size()-1)
        {
            if(a[ind+1]-a[ind]<=mn)
            {
                cnt++;
                ind++;
            }
            ind++;
        }
        
        return cnt;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        int left=0,right=nums[n-1]-nums[0];
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            
            if(helper(nums,mid)>=p)
            {
                right=mid;
            }
            else
            {
                left=mid+1;
            }
        }
        
        return left;
    }
};