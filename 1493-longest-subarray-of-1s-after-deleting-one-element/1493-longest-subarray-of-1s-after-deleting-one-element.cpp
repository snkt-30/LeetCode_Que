class Solution {
public:
    int longestSubarray(vector<int>& a) {
                               
        int l=0,r=0;
        
        int cnt=0,z_cnt=0,o_cnt=0;
        
        int n=a.size();
        
        if(n==0)
            return 0;
        
        int ans=0;
        
        while(r<n)
        {
            if(a[r]==0)
            {
                z_cnt++;
                cnt++;
            }
            else
            {
                o_cnt++;
            }
            
            
            if(cnt==2)
            {
                while(cnt>1 and l<=r and l<n)
                {
                    if(a[l]==0)
                        cnt--;
                    l++;
                }
                // l++;
            }
            
            // cout<<r<<" "<<l<<endl;
            ans=max(ans,r-l);
            cout<<r<<" "<<l<<" "<<ans<<endl;
            r++;
        }
        
        if(z_cnt==n)
        {
            return 0;
        }
        
        if(o_cnt==1)
            return 1;
        
        if(o_cnt==n)
            return n-1;
        
        return ans;;
    }
};