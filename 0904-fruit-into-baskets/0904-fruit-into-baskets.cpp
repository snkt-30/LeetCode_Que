class Solution {
public:
    int totalFruit(vector<int>& f) {
        
        
        int ans=0;
        
        int l=0,r=0;
        
        int n=f.size();
             
        unordered_map<int,int>mp;      
        
        int cnt=0;

        while(r<n)
        {
            // calculation
            
            if(mp[f[r]])
            {
                mp[f[r]]++;
            }
            else
            {
                mp[f[r]]++;
                cnt++;
            }
                    
            // when cnt is < 2

             if(cnt<=2)
            {
                int curr=r-l+1;
                
                ans=max(ans,curr);
                r++;
            }
            else
            {
                while(cnt>2)
                {
                    mp[f[l]]--;
                    if(mp[f[l]]==0)
                        cnt--;
                    l++;
                }
                r++;
            }
            
            // cout<<cnt<<" "<<ans<<endl;

        }
        
        return ans;
    }
};