class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        
        int n=s1.length();
        int m=s2.length();
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
//         for(int i=0;i<n;i++)
//         {
//             a[s1[i]-'a']++;
//         }
        
//         for(int j=0;j<m;j++)
//         {
//             b[s2[j]-'a']++;
//         }
        
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
   
        
        int mx=0;
        
        int row=0,col=0;
    
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
               if(mx<dp[i][j])
               {
                   mx=dp[i][j];
                   row=i,col=j;
               }
            }
        }
        
//         string sqc="";
        
//         while(row>0 and col>0)
//         {
//             // cout<<"here";
//             if(s1[row-1]==s2[col-1])
//             {
//                 sqc+=s1[row-1];
//                 row--,col--;
//             }
//             else
//             {
//                 if(dp[row-1][col]>dp[row][col-1])
//                 {
//                    row--; 
//                 }
//                 else
//                 {
//                     col--;
//                 }
//             }
//         }
        
//        for(auto x:sqc)
//        {
//            a[x-'a']--;
//            b[x-'a']--;
//        }
        
//         int ans=0;
        
        
//         for(int i=0;i<26;i++)
//         {
//             if(a[i]>=1)
//             {
//                 ans+=a[i]*(int)('a'+i);
//             }
            
//             if(b[i]>=1)
//             {
//                 ans+=b[i]*(int)('a'+i);
//             }
//         }
        
//         return ans;
        
         int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=s1[i];
        }
        for(int i=0;i<m;++i)
        {
            sum+=s2[i];
        }
        return sum-2*dp[n][m];
        
        
    }
};