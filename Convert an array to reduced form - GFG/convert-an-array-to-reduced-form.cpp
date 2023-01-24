//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int a[], int n) {
	    // code here
	    
	    vector<int> store(n,0);
	    
	    for(int i=0;i<n;i++)
	    {
	        store[i]=a[i];
	    }
	    
	    sort(store.begin(),store.end());
   
	    map<int,int> mp;
	    
	    for(int i=0;i<n;i++)
	    {
	        mp[store[i]]=i;
	        
	    }
	    
	   // for(int i=0;i<n;i++)
	   // {
	   //     cout<<store[i]<<" ";
	   // }
	   // cout<<endl;
	    
	    for(int i=0;i<n;i++)
	    {
	        int ind=mp[a[i]];
	        a[i]=ind;
	    }

	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends