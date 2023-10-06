class Solution {
    
//     int find_max(int val,vector<int>&dp)
//     {
//         if(val<=4)
//         {
//             return val;
//         }
        
//         if(dp[val]!=-1)
//         {
//             return dp[val];
//         }
        
//         int left=0,right=0;
        
//         int ans=0;
//         for(int i=1;i<=(val/2);i++)
//         {
//             left=find_max(i,dp);
//             right=find_max(val-i,dp);
            
//             ans=max(ans,left*right);dd
//         }
        
//         return dp[val]= max(dp[val],ans);
//     }
public:
    int integerBreak(int n) {
        
        vector<int>dp(60,0);
        
        if(n==1)
            return 0;
        if(n==2)
        {
            return 1;
        }
        
        if(n==3)
        {
            return 2;
        }
        
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++)
        {
            int ans=0;
            int left=0,right=0;
            for(int j=1;j<=(i/2);j++)
            {
                left=dp[j];
                right=dp[i-j];
                
                ans=max(ans,left*right);
                
                cout<<left<<" "<<right<<" "<<ans<<endl;
            }
            
            cout<<i<<" "<<ans<<" finish"<<endl;
            
            dp[i]=max(dp[i],ans);
        }
        
        // int ans=find_max(n,dp);
        return dp[n];
    }
};