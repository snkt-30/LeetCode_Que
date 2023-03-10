//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	
       sort(arr,arr+n);
    	
    	long long res=1;
    	
    	long long ini=1;
    	
    	int cnt=0;
    	
    	if(arr[0]<0)
    	{
    	    ini*=arr[0];
    	    cnt++;
    	}
    	
    	if(arr[1]<0)
    	{
    	    ini*=arr[1];
    	    cnt++;
    	}
    	
    	
    	ini*=arr[n-1];
    	
        long long int ls=1;
    
       ls=arr[n-1]*arr[n-2]*arr[n-3];
    	
    	if(cnt<2)
    	{
    	    return ls;
    	}
    	else
    	{
    	    return max(ls,ini);
    	}

    	
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends