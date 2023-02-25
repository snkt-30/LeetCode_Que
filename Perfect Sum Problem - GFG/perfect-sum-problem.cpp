//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007

class Solution{
    
    private:
    
     int helper(int a[],int n,int ind,int sum, vector<vector<int>>&dp)
     {
         if(ind==n)
         {
             if(sum==0)
                return 1;
              
             return 0;
         }
         
         if(dp[ind][sum]!=-1)
           return dp[ind][sum];
         
         int take=0;
         
         if(a[ind]<=sum)
           take=helper(a,n,ind+1,sum-a[ind],dp)%mod;
           
          int not_take=helper(a,n,ind+1,sum,dp)%mod;
          
          return dp[ind][sum]=((take%mod)+(not_take%mod))%mod;
     }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        // int cnt=0;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        for(int i=0;i<=sum;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int take=0;
                
                if(arr[i-1]<=j)
                {
                    take=dp[i-1][j-arr[i-1]]%mod;
                }
                
                int not_take=dp[i-1][j]%mod;
                
                dp[i][j]=((take%mod)+(not_take%mod))%mod;
                
                
            }
        }
        
        // int ans= helper(arr,n,0,sum,dp);
        
        int ans=dp[n][sum];
         
         
        //   for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends