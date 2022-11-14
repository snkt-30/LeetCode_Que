//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        
        string s="";
        
        int n=S.length(), wn=W.length();
        
        
        int ind=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int ind=0;
            if(S[i]==W[ind]){
                for(int j=i;j<n;j++){
                    if(S[j]==W[ind])
                    {
                        // cout<<S[j];
                        S[j]='#';
                        ind++;
                    }
                    if(ind==wn)
                    {
                        ans++;
                        break;
                    }
                }
                // cout<<endl;
                
            }
        }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends