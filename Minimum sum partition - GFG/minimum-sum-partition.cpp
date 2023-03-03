//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    ll sum=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
	    
	    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
	    
	    for(int i=0;i<=sum;i++)
	    {
	        dp[0][i]=false;
	    }
	    
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0]=true;
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            bool take=false;
	            
	            if(arr[i-1]<=j)
	            {
	                take=dp[i-1][j-arr[i-1]];
	            }
	            
	            bool not_take=dp[i-1][j];
	            
	            dp[i][j]=(take or not_take);
	        }
	    }
	    
	    vector<int>v;
	    
	    for(int i=0;i<=(sum/2);i++)
	    {
	        if(dp[n][i]==true)
	        {
	            v.push_back(i);
	           // cout<<i<<" ";
	        }
	    }
	    
	    ll ans=INT_MAX;
	    
	    for(int i=0;i<v.size();i++)
	    {
	        ans=min(ans,sum-(2*v[i]));
	    }
	    
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