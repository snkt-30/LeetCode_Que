//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int r_cnt=0,g_cnt=0,b_cnt=0;
        
        for(int i=0;i<n;i++)
      {
            if(a[i]=='R')
                r_cnt++;
            else if(a[i]=='G')
              g_cnt++;
            else
               b_cnt++;
        }
        
        // cout<<r_cnt << " "<<g_cnt<<" "<<b_cnt<<endl;
          
      if((r_cnt==0 and b_cnt==0 )or (b_cnt==0 and g_cnt==0) or (g_cnt==0 and r_cnt==0))
          return n;
      else if(r_cnt%2==0 and b_cnt%2==0 and g_cnt%2==0)
         return 2;
      else if(r_cnt%2!=0 and b_cnt%2!=0 and g_cnt%2!=0)
        return 2;
       else
         return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends