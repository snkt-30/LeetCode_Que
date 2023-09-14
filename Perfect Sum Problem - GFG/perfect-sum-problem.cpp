//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{
    
    private:
    
    int helper(int ind,int sum,int a[],int n, vector<vector<int>>&dp)
    {
       if(ind==n)
       {
           if(sum==0)
             return 1;
           
           return 0;
       }
       
       if(dp[ind][sum]!=-1)
       {
           return dp[ind][sum];
       }
          
        //   if(sum<0)
        //     return 0; 
            
        int take=0,not_take=0;
        
        if(sum>=a[ind])
          take=helper(ind+1,sum-a[ind],a,n,dp)%mod;
          
        not_take=helper(ind+1,sum,a,n,dp)%mod;
        
        return dp[ind][sum]=(take+not_take)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(0,sum,arr,n,dp)%mod;
        
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