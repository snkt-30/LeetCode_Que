//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    
    stack<char> st;
    
    int i=0;
    int n=num.length();
    
    while(i<n)
    {
        if(st.empty())
        {
            st.push(num[i]);
        }
        else
        {
            if(st.top()>num[i])
            {
                while(!st.empty() and st.top()>num[i] and k>0)
                {
                    st.pop();
                    k--;
                }
            }
            st.push(num[i]);
        }
        i++;
    }
    
    if(k>0)
    {
        while(!st.empty() and k>0)
        {
            st.pop();
            k--;
        }
    }
    string ans="";
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    
    // if(ans[0]=='0' and ans[ans.length()-1]=='0')
    //     return "0";
        
    int ind=ans.length()-1;
    
    while(ind>=0 and ans[ind]=='0')
    {
        ans.pop_back();
        ind--;
    }
    
    reverse(ans.begin(),ans.end());
    
    ind=ans.length();
    
      while(ind>=0 and ans[ind]=='0')
    {
        ans.pop_back();
        ind--;
    }
    
    
    if(ans.length()==0)
      return "0";
    
    return ans;
    
    
       
}