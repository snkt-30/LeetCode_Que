//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        
        if(M!=N)
          return 0;
          
         string s="",t="";
         
         
         for(int i=0;i<M;i++)
         {
            if(S[i]!='#')
               s.push_back(S[i]);
         }
         
          for(int i=0;i<N;i++)
         {
            if(T[i]!='#')
               t.push_back(T[i]);
         }
         
         if(s!=t)return 0;
         
         int i=0,j=0;
         
         
         while(i<M and j<N)
         {
             while(i<M and S[i]=='#')i++;
             while(j<N and T[j]=='#')j++;
             
             if(S[i]=='A')
             {
                 if(j>i)return 0;
             }
             if(S[i]=='B')
             {
                 if(j<i)return 0;
             }
             i++;
             j++;
         }
         
         return 1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends