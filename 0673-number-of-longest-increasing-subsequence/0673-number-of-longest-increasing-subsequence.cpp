class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        
        
        int n=a.size();
        
        if(n==1)
        {
            return 1;
        }
        
        if(n==2)
        {
            if(a[0]<a[1])
            {
                return 1;
            }
            return 2;
        }
        
        
        vector<int>dp(n,1);
        
        int mx=0;
        
        int ind=0;
        
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            
            while(j>=0)
            {
                if(a[j]<a[i])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
                j--;
            }
            
            mx=max(mx,dp[i]);
        }
        
        vector<int>indices;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==mx)
            {
                indices.push_back(i);
            }
        }
        if(mx==1)
        {
            return n;
        }
        
        map<int,int>mp;
        
        vector<int>cac(n,0);
        cac[0]=1;
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            int ls=dp[i]-1;
            
            int ways=0;
            
            while(j>=0)
            {
                if(a[j]<a[i] and dp[j]==ls)
                {
                    ways+=cac[j];
                }
                j--;
            }
            
            if(ways==0)
            {
                cac[i]=1;
            }
            else
            {
                cac[i]=ways;
            }
        }
            
       int res=0;
        
//         for(int i=0;i<n;i++)
//         {
            
//             cout<<dp[i]<<" "<<cac[i]<<
//         }
        
        
        for(auto x:indices)
        {
            res+=cac[x];
        }
        return res;
    }
};