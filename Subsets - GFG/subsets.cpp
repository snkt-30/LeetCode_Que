//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void solve(vector<vector<int>>&ans,vector<int>&ds,vector<int>&ar,int ind)
    {
        if(ind==ar.size())
        {
            ans.push_back(ds);
            return;
        }
        
         solve(ans,ds,ar,ind+1);
         
        ds.push_back(ar[ind]);
        
        solve(ans,ds,ar,ind+1);
        
        ds.pop_back();
        
        // solve(ans,ds,ar,ind+1);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<int>ds;
        vector<vector<int>>ans;
        
        solve(ans,ds,A,0);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends