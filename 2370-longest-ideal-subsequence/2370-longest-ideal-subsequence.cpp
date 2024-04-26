class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int> values(26,0);
        
        int n= s.length()-1;
        
        // cout<<s[n]-'a'<<endl;
        
        values[s[n]-'a']=1;
        
        int ans=1;
        
        // int ans=0;
        
        for(int i=s.length()-2;i>=0;i--)
        {
            int val = s[i]-'a';
            
            int mx=0;
            
            for(int rng = max(val - k,0);rng<=min(val+k,25);rng++)
            {
                mx = max(mx,values[rng]);
            }
            
            values[val]=max(values[val],mx+1);
            
            ans=max(ans,values[val]);
        }
        
       
        
        
        return ans;
        
    
    }
};