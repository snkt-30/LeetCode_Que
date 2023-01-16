#define ll long long int 


class Solution {
    
    private:
    static bool isPossible(vector<int>&nums,int k,ll range)
    {
        int mx_days=1;
        ll mx_ele=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>range)return false;
            
            if(mx_ele + nums[i] > range)
            {
                mx_days+=1;
                mx_ele=nums[i];
            }
            else
            {
                mx_ele+=nums[i];
            }
        }
        
        if(mx_days > k)return false;
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        
        ll sum=0;
        
        int mx=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }
        
        ll lo=mx,hi=sum;
        
        ll ans=INT_MAX;
        
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            if(isPossible(nums,k,mid))
            {
                hi=mid-1;
                ans=min(mid,ans);
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
        
    }
};