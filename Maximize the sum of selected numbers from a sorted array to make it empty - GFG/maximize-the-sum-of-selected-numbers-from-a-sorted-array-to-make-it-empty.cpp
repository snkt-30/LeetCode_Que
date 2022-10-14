//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        unordered_map<int,int> mp;
        long long int ans=0;
        
        
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++; 
        }
        
        sort(a,a+n);
        
        for(int i=n-1;i>=0;i--)
        {
            if(mp[a[i]]==0)
            {
                continue;
            }
            else
            {
                mp[a[i]]--;
                
                if(mp[a[i]-1]!=0)
                {
                    mp[a[i]-1]--;
                }
                // cout<<ans<<endl;
                ans+=a[i];
            }
        }
        
        return ans;
        
        
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends