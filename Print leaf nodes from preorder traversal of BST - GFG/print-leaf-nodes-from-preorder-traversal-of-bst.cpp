//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        
        vector<int>ans;
        
       stack<int> st;
       st.push(arr[0]);
       for(int i=1;i<N;i++)
       {
           if(arr[i]<st.top())
           {
               st.push(arr[i]);
           }
           else
           {
               if(arr[i]>st.top())
               {
                   int x=st.top();
                   int cnt=0;
                   while(!st.empty() and st.top()<arr[i])
                   {
                       st.pop();
                       cnt++;
                   }
                   st.push(arr[i]);
                   if(cnt>=2)
                   {
                       ans.push_back(x);
                   }
               }
           }
       }
       ans.push_back(st.top());
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
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends