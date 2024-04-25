class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int> values(26,0);
        
        int n= s.length()-1;
        
        // cout<<s[n]-'a'<<endl;
        
        values[s[n]-'a']=1;
        
        // int ans=0;
        
        for(int i=s.length()-2;i>=0;i--)
        {
            int val = s[i]-'a';
            
            int mx=0;
            
            for(int rng = max(val - k,0);rng<=min(val+k,25);rng++)
            {
                mx = max(mx,values[rng]);
                // cout<<values[rng]<<mx<<" ";
            }
            
            // cout<<endl;
            
            // cout<<mx<<" "<<ans<<endl;
            
            // ans=max(ans,mx+1);
            values[val]=max(values[val],mx+1);
            // cout<<values[val]<<" "<<val<<" "<<ans<<endl;
        }
        
        int ans=0;
        
        for(int i=0;i<26;i++)
        {
            ans=max(ans,values[i]);
        }
        
        
        
        return ans;
        
    
    }
};