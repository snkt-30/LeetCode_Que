
#define ll long long int

class Solution {
    private:
    static bool isPossible(vector<int>&pos,int k,ll range)
    {
        int balls=1;
        ll ls_balls=pos[0];
        ll dist=0;
        
        for(int i=0;i<pos.size();i++)
        {
            if(dist>=range)
            {
                balls++;
                
                ls_balls=pos[i-1];
                 dist=abs(ls_balls-pos[i]);
            }
            else
            {
                dist=abs(ls_balls-pos[i]);
            }
        }
        
        if(dist>=range)
            balls++;
        
        if(balls < k) return false;
        
        return true;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        
        
        sort(position.begin(),position.end());
        ll lo=1 , hi=position[position.size()-1];
        
        ll ans=0;
        
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            
            if(isPossible(position,m,mid))
            {
                ans=max(ans,mid);
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        
        return ans;
        
        
    }
};