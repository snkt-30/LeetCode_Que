class Solution {

public:
    int longestSubsequence(vector<int>& a, int d) {
        
        unordered_map<int,int>mp;  // element  and its index
        
        int n=a.size();
        
        int dp[100001];
        
        int mx=-1;
        
        for(int i=0;i<n;i++)
        {
            int val=a[i]-d;
            
            if(mp.find(val)!=mp.end())
            {
                int ind=mp[val];
                
                dp[i]=1+dp[ind];
            }
            else
            {
                dp[i]=1;
            }
            mx=max(mx,dp[i]);
            
            mp[a[i]]=i;
        }
        
        return mx;
    }
};