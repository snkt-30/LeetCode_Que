//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int

class Solution{
    
    
    private:
    ll helper(int arr[],int ind,int curr_sum,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            ll val=sum;
            
            val=val-2*curr_sum;
            
            return val;
        }
        
        if(dp[ind][curr_sum]!=-1)
        {
            return dp[ind][curr_sum];
        }
        
    
    ll take=100005;
    
    if(arr[ind-1]+curr_sum <= s2)
    {
        take=helper(arr,ind-1,curr_sum+arr[ind-1],dp);
    }
    
    ll not_take=helper(arr,ind-1,curr_sum,dp);
    
    return dp[ind][curr_sum]=min(take,not_take);
    }
   
  public:
  
   ll sum=0;
   ll s2=0;
   ll ans=INT_MAX;
   
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    
	     s2=(sum)/2;
	     
	     vector<vector<int>> dp(n+1,vector<int>(s2+1,-1));
	     
	     return helper(arr,n,0,dp);
	     
	     
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends