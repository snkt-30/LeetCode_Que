//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    private:
    void tk_not_tk(int ind,vector<int>&a,vector<int>&ds,int n,int target,vector<vector<int>>&ans)
    {
        if(target<0)return;
        
        if(ind==a.size())
        {
            if(target==0)
            {
                // reverse(ds.begin(),ds.end());
                ans.push_back(ds);
            }
            
            return;
        }
        
        ds.push_back(a[ind]);
        tk_not_tk(ind,a,ds,n,target-a[ind],ans);

        ds.pop_back();
        tk_not_tk(ind+1,a,ds,n,target,ans);
        
     
      
    }
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
      vector<vector<int>>ans;
      vector<int>ds;
      
     vector<int>a;
     
     for(int i=n;i>=1;i--)
     {
         a.push_back(i);
     }
      
      tk_not_tk(0,a,ds,n,n,ans);
      
    //   reverse(ans.begin(),ans.end());
      
    //   for(int i=0;i<ans.size();i++)
    //   {
    //       for(int j=0;j<ans[i].size();j++)
    //       {
    //           cout<<ans[i][j]<<" ";
    //       }
    //       cout<<endl;
    //   }
      
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
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends