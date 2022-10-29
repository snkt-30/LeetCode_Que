//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // // code her

        
        set<string> st;
        
        for(int i=0;i<n;i++)
        {
            st.insert(contact[i]);
        }
        vector<vector<string>>ans;
        string pat="";
        for(int i=0;i<s.length();i++)
        {
            pat+=s[i];
            vector<string>temp;
            
            for(auto t:st)
            {
               string x=t.substr(0,i+1);
               
             if(i>=t.length())
                 continue;
             else if(pat==x)
               temp.push_back(t);
            }
            
            sort(temp.begin(),temp.end());
            if(temp.size()==0)
            {
                ans.push_back({"0"});
            }
            else
            {
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends