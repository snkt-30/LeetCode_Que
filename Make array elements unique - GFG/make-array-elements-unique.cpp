//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int n) {
        // Code here
        
        sort(arr.begin(),arr.end());
        
        map<int,int>mp;
        
        set<int> s;
        
        for(auto x:arr)
        {
            mp[x]++;
            s.insert(x);
        }
        
        int i=0;
        
        long long int ans=0;
        
        
        long long int prev=0;
        long long int curr=0;
        
        
        
        int ind=0;
        
       for(auto x:s)
       {
           int ele=x;
          int cnt=mp[ele];
            
            if(ele>prev)
            {
                
                prev=ele+(cnt-1);
                
                --cnt;
                
                long long int sum=(cnt*(cnt+1))/2;

                ans+=sum;
            }
            else
            {
                long long int diff=prev+1-ele;
                
                long long int mxinc=diff+cnt-1;
                
                long long int mx_sum=(mxinc*(mxinc+1))/2;
                
                --diff;
                
                long long int remsum=(diff*(diff+1))/2;
                
                ans+=(mx_sum-remsum);
                
                prev=ele+mxinc;
                
            }
            
            // cout<<ans<<endl;
       }
       return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends