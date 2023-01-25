//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        
        int cnt=1;
        
        int n=s.length();
        
        int i=1;
        
       while(i<n)
        {
            if(s[i]==s[0])
            {
                int ind=0;
                int st=i;
                int c=0;
                while(s[i]==s[ind] and ind<st and i<n)
                {
                    i++;
                    ind++;
                    c++;
                }
                
                if(c==st)
                {
                    cnt=st+1;
                }
                else
                {
                    i=st+1;
                    cnt++;
                }
            }
            else
            {
                cnt++;
                i++;
            }
          
        }
        
        return cnt;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends