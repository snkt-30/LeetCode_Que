class Solution {
    
    private:
    
    bool isValid(vector<int>&a,int d,int mx_w)
    {
        
        int days=1;
        
        int curr_day_wei=0;
        
        for(int i=0;i<a.size();i++)
        {
            
            if(a[i]>mx_w)
                return false;
            
            if(curr_day_wei+a[i]>mx_w)
            {
                days++;
                curr_day_wei=a[i];
            }
            else
            {
                curr_day_wei+=a[i];
            }
        }
        
        if(days>d)
            return false;
        
        return true;
    }
public:
    int shipWithinDays(vector<int>& a, int days) {
        
        int mx=0,sum=0;
        
        for(int i=0;i<a.size();i++)
        {
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        
        int lo=1,hi=sum;
        
        int res=0;
        
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            
            if(isValid(a,days,mid))
            {
                res=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return res;
    }
};