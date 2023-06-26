#define mk make_pair

class Solution {
public:
    long long totalCost(vector<int>& a, int k, int slab) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>  , greater<pair<int,int>>>pq;
        
     int n=a.size();
        
      int l=0,r=n-1;
        
        if(n==1)
        {
            return a[0];
        }
        
        if(n>=(slab*1LL*2))
        {
            for(int i=0;i<slab;i++)
            {
                pq.push(mk(a[i],i));
                l++;
            }
            
            for(int i=n-1;i>n-1-slab;i--)
            {
                pq.push(mk(a[i],i));
                r--;
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                pq.push(mk(a[i],i));
                // cout<<a[i]<<" "<<i<<endl;
            }
            l=n-1,r=0;
        }
//         l++,r--;
        
        long long int ans=0;
        
        while(k--)
        {
            auto x=pq.top();
            pq.pop();
            
            ans+=x.first;
            
            if(l<=r)
            {
                if(x.second<=l)
                {
                    pq.push(mk(a[l],l));
                    l++;
                }
                else
                {
                   pq.push(mk(a[r],r));
                    r--;
                }
            }
            // cout<<x.first<<" "<<ans<<endl;
        }
        return ans;
    }
};