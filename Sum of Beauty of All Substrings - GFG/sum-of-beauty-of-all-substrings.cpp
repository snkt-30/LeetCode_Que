//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        
        int n=s.length();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>mp(26,0);
            for(int j=i;j<n;j++)
            {
             int mx=INT_MIN;
            int mn=INT_MAX;
                mp[s[j]-'a']++;
                for(int freq=0;freq<26;freq++)
                {
                    if(mp[freq]==0)continue;
                    
                    mx=max(mx,mp[freq]);
                    mn=min(mn,mp[freq]);
                }
                
                ans+=(mx-mn);
                
                //   cout<<i<<" "<<j<<" "<<mx<<" "<<mn<<" "<<ans<<endl;
                
                
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends