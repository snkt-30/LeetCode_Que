#define ll long long int 
class Solution {
    private:
    static bool isPossible(vector<int>&w,int days,int range)
    {
        int mx_days=1;
        ll pack=0;
        
        for(int i=0;i<w.size();i++)
        {
            if(w[i]>range)return false;
            
            if(pack + w[i] > range)
            {
                mx_days+=1;
                pack=w[i];
            }
            else
            {
                pack+=w[i];
            }
        }
        
        if(mx_days > days)return false;
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& w, int d) {
        
        
        // let say if we ship the packages less than given days then we got our possible ans 
        // in order to minimize it we have to find the less value than gotten as if we got our 
        // ans let say 115 and we ship all package in 2 day instead of 5 days the we got out 
        // ans no we have to find the as minimum value as we can find than 115 to get out 
        // desired ans
        
        // it is like standard pages allocation problem
        
        // no our ranges of searches will be
        // no let say i have atleast max of all ele is the least capacity of ship
        
        int mx_weight=INT_MIN;
        
        ll sum=0;
        
        for(int i=0;i<w.size();i++)
        {
            int x=w[i];
            mx_weight=max(mx_weight,x);
            sum+=x;
        }
        
        ll lo=mx_weight,hi=sum;
        
        ll ans=INT_MAX;
  
        while(lo <= hi)
        {
            ll mid=(lo+hi)/2;
            if(isPossible(w,d,mid))
            {
                ans=min(ans,mid);
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;
    
    }
};