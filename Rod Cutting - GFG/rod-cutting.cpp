//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    private:
    
    int helper(int p[],int ind,int rod_len,vector<vector<int>>&dp)
    {
        
        if(ind==0)
        {
            return 0;
        }
        
        if(dp[ind][rod_len]!=-1)
        {
            return dp[ind][rod_len];
        }
        
        int take=0;
        
        if(ind<=rod_len)
        {
            take=p[ind-1]+helper(p,ind,rod_len-ind,dp);
        }
        
        int not_take=helper(p,ind-1,rod_len,dp);
        
        dp[ind][rod_len]=max(take,not_take);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
       return helper(price,n,n,dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends