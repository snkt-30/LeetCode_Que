//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long int 
class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        
        
        ll ans1=0,ans2=0;
        
        int c1=c,d1=d,a1=a,b1=b;
        
        while(a1>c1)
          {
              a1/=2;
              ans1++;
          }
          
          while(d1<b1)
          {
              b1/=2;
              ans1++;
          }
          
          
          int a2=b,b2=a,c2=c,d2=d;
          
          while(a2>c2)
          {
              a2/=2;
              ans2++;
          }
          while(b2>d2)
          {
              b2/=2;
              ans2++;
          }
          
          
          return min(ans1,ans2);
        
        
        
        
         
              
        
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends