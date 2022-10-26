//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        
        long long int ans=INT_MIN;
      for(long long int i=2;i*i<=n;i++)
      {
          if(n%i==0)
          {
              int cnt=0;
              
              while(n%i==0)
              {
                  cnt++;
                  n/=i;
              }
            //   cout<<cnt<<" "<<i<<endl;
              ans=max(ans,i);
          }
          
      }
      if(n>1)
      {
          return n;
      }
      return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends