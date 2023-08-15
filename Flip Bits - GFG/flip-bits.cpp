//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        
        int cnt=0;
         int l=-1,r=-1;
        
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==0 and l==-1 and r==-1)
            {
                l=i,r=i;
            }
            
            if(a[i]==1)
            {
                cnt++;
            }
        }
        
        if(r==-1)
        {
            r=n;
        }
        int cn=0;
        int mx=INT_MIN;
        while(r<n)
        {
            if(a[r]==0)
            {
                cn++;
            }
            else
            {
                cn--;
            }
            
            
           if(cn<0)
           {
               while(cn<0 and l<=r)
               {
                   if(a[l]==1)
                   cn++;
                   l++;
               }
           }
           
           mx=max(mx,cn);
           r++;
        }
        
        mx=max(mx,cn);
        return (cnt+mx);
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends