//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    
	    int n=nums.size();
	    vector<int> inc(n),dec(n);
	    
	   // inc[0]=1;
	   // dec[n-1]=1;
	    
	    for(int i=0;i<n;i++)
	    {
	        inc[i]=1;
	        for(int j=i-1;j>=0;j--)
	        {
	            if(nums[i]>nums[j] and inc[j]+1>inc[i])
	            {
	                inc[i]=inc[j]+1;
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        dec[i]=1;
	        for(int j=i+1;j<n;j++)
	        {
	            if(nums[i]>nums[j] and dec[j]+1>dec[i])
	            {
	                dec[i]=dec[j]+1;
	            }
	        }
	    }
	    
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,inc[i]+dec[i]-1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends