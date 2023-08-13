//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007

class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        
        int f=1,s=1;
        
        if(n==1 or n==2)
        {
            return 1;
        }
        
        int curr=0;
        
        for(int i=3;i<=n;i++)
        {
            curr=(f%mod+s%mod)%mod;
            
            f=(s%mod);
            s=(curr%mod);
        }
        
        return (curr%mod);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends