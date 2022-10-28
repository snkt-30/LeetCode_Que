//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	int mod=1000000007;
		int NthTerm(int n){
		    // Code  here
		    long long  prev=2;
		    long long int ans=0;
		    
		    if(n==0)
		    {
		        return 1;
		    }
		    
		    if(n==1)
		    {
		        return 2;
		    }
		    for(long long int i=2;i<=n;i++)
		    {
		        ans=(((prev%mod)*i%mod)%mod+1%mod)%mod;
		        
		        prev=ans%mod;
		    }
		    
		    return ans;
		 
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends