#define ll long long

class Solution {
    
    private:
    
    bool check(int speed,vector<int>&dist,double hr)
    {
        
        ll ans=0;
        
        int n=dist.size();
        
        for(int i=0;i<n;i++)
        {
            double curr=(double)dist[i]/(double)speed;
            
            double temp=(double)ans+curr;
            
            if(temp>hr)
                return false;
            
            ans=ans+(ceil(curr)); 
        }
        
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        ll sum=0;
        
        ll lo=1,hi=1e7;
        
        
        
        ll ans=-1;
        while(lo<=hi)
        {
            float mid=(lo+hi)/2;
            
            // cout<<"for "<<mid<<endl;
            if(check(mid,dist,hour)==true)
            {
                ans=mid;
                hi=mid-1;
                
                // cout<<mid<<endl;
            }
            else
            {
                lo=mid+1;
            }
        }
        
        return ans;

    }
};