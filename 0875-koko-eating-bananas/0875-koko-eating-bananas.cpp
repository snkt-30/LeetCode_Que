class Solution {
    
    private:
    
    bool check(vector<int>& a,int hr,int k)
    {
        int curr_hr=0;
        
       for(int i=0;i<a.size();i++)
       {
           if(a[i]%k==0)
           {
               curr_hr+=(a[i]/k);
           }
           else
           {
               curr_hr+=(a[i]/k)+1;
           }
           
           if(curr_hr>hr)
           {
               return false;
           }
       }
        
        
        if(curr_hr>hr)
            return false;
        
        return true;
        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

         int mn=INT_MIN;
        
        for(int i=0;i<piles.size();i++)
        {
            mn=max(mn,piles[i]);
        }
        
        long long int lo=1,hi=mn;
        
        long long int ans=INT_MAX;
        
        while(lo<=hi)
        {
            long long int mid=(lo+hi)/2;
            
            if(check(piles,h,mid))
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