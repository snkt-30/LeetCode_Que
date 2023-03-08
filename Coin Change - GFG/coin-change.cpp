//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    long long int helper(int a[],int ind,int sum,vector<vector<long long int>>&dp)
    {
        if(ind==0)
        {
            if(sum==0)
              return 1;
             
             return 0;
        }
        
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
        
        long long int take=0;
        
        if(a[ind-1]<=sum)
        {
            take=helper(a,ind,sum-a[ind-1],dp);
        }
        
       long long int not_take=helper(a,ind-1,sum,dp);
        
        return dp[ind][sum]=(take + not_take);
    }
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1));
        
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
              long long  int take=0;
                
                if(j>=coins[i-1])
                {
                    take=dp[i][j-coins[i-1]];
                }
                
              long long  int not_take=dp[i-1][j];
                
                dp[i][j]=(take+not_take);
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends