//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    set<vector<int>>res;
    
    bool helper(int o_row,int o_col,int row,int col,vector<vector<char>>&mat,string word,int ind,int side)
    {
        if(row<0 or col<0 or row>=mat.size() or col>= mat[0].size() or mat[row][col]!=word[ind])
        {
            return false;
        }
        
        if(ind==word.length()-1)
        {
            if(mat[row][col]==word[ind])
              {
                 res.insert({o_row,o_col});
                   return true;
              }
            return false;
        }
        
        bool ans=false;
        
        //up
        if(side==0 or side==1)
        {
            ans=helper(o_row,o_col,row-1,col,mat,word,ind+1,1);
        }
        
        //down
         if(side==0 or side==2 )
        {
            ans=helper(o_row,o_col,row+1,col,mat,word,ind+1,2);
        }
        
        
        //left
         if(side==0 or side==3)
        {
            ans=helper(o_row,o_col,row,col-1,mat,word,ind+1,3);
        }
        
        
        // right
         if(side==0 or side==4)
        {
            ans=helper(o_row,o_col,row,col+1,mat,word,ind+1,4);
        }
        
        
        //upleft
         if(side==0 or side==5 )
        {
            ans=helper(o_row,o_col,row-1,col-1,mat,word,ind+1,5);
        }
        
        
        //upright
         if(side==0 or side==6)
        {
            ans=helper(o_row,o_col,row-1,col+1,mat,word,ind+1,6);
        }
        
        
        //downleft
         if(side==0 or side==7)
        {
            ans=helper(o_row,o_col,row+1,col-1,mat,word,ind+1,7);
        }
        
        //downright
         if(side==0 or side==8)
        {
            ans=helper(o_row,o_col,row+1,col+1,mat,word,ind+1,8);
        }
        return ans;
    }
    
    
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++){
	            
	            if(word[0]==grid[i][j])
	            {
	                helper(i,j,i,j,grid,word,0,0);
	            }
	        }
	    }
	    
	    vector<vector<int>> ans;
	    
	  while(!res.empty())
	  {
	      auto x = * res.begin();
	      res.erase(x);
	      
	      ans.push_back(x);
	  }
	    
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends