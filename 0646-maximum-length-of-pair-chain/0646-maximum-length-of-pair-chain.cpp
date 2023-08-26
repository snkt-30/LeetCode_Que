class Solution {
    
//     int helper(int lst_take,int ind,vector<vector<int>>&a,int dp[1001][1001])
//     {
        
//         if(ind==a.size())
//         {
//             return 0;
//         }
        
//         if(dp[ind][lst_take]!=-1)
//         {
//             return dp[ind][lst_take];
//         }
        
//         int take=0,not_take=0;
        
//         if(a[ind][0]>a[lst_take][1])
//         {
//             take=1+helper(ind,ind+1,a,dp);
//         }
        
//         not_take=helper(lst_take,ind+1,a,dp);
        
//         return dp[ind][lst_take]= max(take,not_take);
//     }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
           
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            
            if(a[1]==b[1])
            {
                return a[0]<b[0];
            }
            return(a[1]<b[1]);
        });
        
        vector<int>last=pairs[0];
        
        int cnt=1;
        
        for(auto x:pairs)
        {
            if(x[0]>last[1])
            {
                last=x;
                cnt++;
            }
        }
        
        return cnt;
        
//         int dp[1001][1001];
        
//         memset(dp,-1,sizeof(dp));
        
//        return helper(0,0,pairs,dp)+1;
        
    }
};