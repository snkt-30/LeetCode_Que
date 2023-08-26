//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
       int r=0,l=0;
       
       int n=s.length();
       
       int ans=-1;
          
       
       unordered_map<char,int>mp;
       
       while(r<n)
       {
           if(mp[s[r]]==0)
           {
               k--;
           }
           
           mp[s[r]]++;
           
           if(k==0)
           {
            //   cout<<r<<" "<<l<<endl;
               ans=max(ans,r-l+1);
           }
           else if(k<0)
           {
               while(k<0 and l<=r)
               {
                   mp[s[l]]--;
                   if(mp[s[l]]==0)
                   {
                       k++;
                   }
                   l++;
               }
               
              ans=max(ans,r-l+1);
           }
           r++;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends