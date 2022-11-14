//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>> pos(n);
	    
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        pos[i].first=nums[i];
	        pos[i].second=i;
	    }
	    sort(pos.begin(),pos.end());
	    for(int i=0;i<n;i++)
	    {
	        if(pos[i].second==i)continue;
	        else
	        {
	            while(pos[i].second!=i)
	            {
	                ans++;
	                swap(pos[i],pos[pos[i].second]);
	            }
	        }
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends