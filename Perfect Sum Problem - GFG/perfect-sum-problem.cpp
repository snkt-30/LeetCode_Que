//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        
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
                    take=dp[i-1][j-arr[i-1]];
                }
                
                int not_take=dp[i-1][j];
                
                dp[i][j]=(take%mod+not_take%mod)%mod;
            }
        }
        
        return dp[n][sum];
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