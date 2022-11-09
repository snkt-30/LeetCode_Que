//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
int solve(int i,int summ,int sum,int arr[],int n,vector<vector<int>>&dp){

        if(i==n){

            return abs(sum-2*summ);

        }

        if(dp[i][summ]!=-1)return dp[i][summ];

        int pick=solve(i+1,summ+arr[i],sum,arr,n,dp);

        int notpick=solve(i+1,summ,sum,arr,n,dp);

        return dp[i][summ]=min(pick,notpick);

    }

 int minDifference(int arr[], int n)  { 

     // Your code goes here

     int sum=0;

     for(int i=0;i<n;i++){

         sum+=arr[i];

     }

     vector<vector<int>>dp(n,vector<int>(sum,-1));

     return solve(0,0,sum,arr,n,dp);

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