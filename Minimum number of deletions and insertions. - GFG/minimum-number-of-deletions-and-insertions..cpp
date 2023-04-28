//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string a, string b) 
	{ 
	    // Your code goes here
	    
	    int n=a.length();
	    int m=b.length();
	    
	    int dp[n+1][m+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0 or j==0)
	            {
	                dp[i][j]=0;
	                continue;
	            }

	                if(a[i-1] == b[j-1])
	                {
	                    dp[i][j] = 1 + dp[i-1][j-1];
	                }
	                else
	                {
	                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
	                }
	        }
	    }
	    
	    int lcs=dp[n][m];
	    
	   // cout<<lcs;
	    
	    int ans=0;
	    
	    ans+=(m-lcs)+(n-lcs);
	    
	    
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
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends