//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        
        int mn=INT_MAX;
        int mx=1;
        
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            mn=min(mn,x);
            mx=max(mx,x);
        }
        
        int ans=0;
        vector<int>freq(mx+1);
        
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            freq[x]=1;
        }
        
        for(int i=mn;i<=mx;i++)
        {
            if(freq[i]!=0)
            {
                for(int j=i+i;j<=mx and (j/i)<=i;j+=i)
                {
                    if(freq[j]!=0)
                    {
                        freq[j]+=(freq[i]*freq[j/i]);
                        if(i!=(j/i))
                        {
                            freq[j]+=(freq[i]*freq[j/i]);
                        }
                    }
                }
                
                ans=(ans + freq[i]) % 1000000007;
            }
            
        }
        return ans% 1000000007;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends