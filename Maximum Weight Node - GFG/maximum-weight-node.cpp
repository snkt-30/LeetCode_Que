//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> e)
  {
      // code here
      map<int,int>mp;
      
      for(int i=0;i<n;i++)
      {
          if(e[i]>=0)
          {
              mp[e[i]]+=i;
          }
      }
      
      int ans=0,mx=0;
      
      for(auto x:mp)
      {
          if(x.second>mx)
          {
              ans=x.first;
              mx=x.second;
          }
          
          if(x.second==mx)
          {
              ans=max(x.first,ans);
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends