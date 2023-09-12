//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        
        if(N==1 or N==2)
        {
            return 0;
        }
        
        int n=sqrt(N);
        
        if(n*1LL*n!=N)
        {
            n+=1;
        }
        
       long long int ans=1;
        for(long long int i=2;i*i<=N;i++)
        {
            if(i*i==N)
            {
               ans+=i; 
            } 
           else if(N%i==0)
            {
                ans+=i;
                ans+=(N/i);
            }
        }
        
        // cout<<ans<<endl;
        
        return (ans==N);
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends