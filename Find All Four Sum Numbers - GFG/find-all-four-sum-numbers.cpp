//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        
        sort(arr.begin(),arr.end());
        
        
        int n=arr.size();
        
        if(n<=3)
        {
            return {};
        }
        
     set<vector<int>>st;
        
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                
                long long sum=arr[i]+arr[j];
               int lo=j+1,hi=n-1;
               
               long long target=k-sum;
               
               while(lo<hi)
               {
                   long long temp=arr[lo]+arr[hi];
                   
                   if(temp==target)
                   {
                      st.insert({arr[i],arr[j],arr[lo],arr[hi]});
                       hi--;
                   }
                   else if(temp<target)
                   {
                       lo++;
                   }
                   else
                   {
                       hi--;
                   }
               }
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto x:st)
        {
            ans.push_back(x);
        }
        
        // sort(ans.begin(),ans.end());
        
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends