//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    
    private:
    
    bool isValid(int row,int col,int n,int m)
    {
        return (row>=0 and row<n and col>=0 and col<m);
    }
public:
    int Count(vector<vector<int> >& mat) {
        // Code 
        
        int n=mat.size();
        int m=mat[0].size();
        
        int ones=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    int cnt=0;
                    for(int a=-1;a<=1;a++)
                    {
                        for(int b=-1;b<=1;b++)
                        {
                            int row=i+a;
                            int col=j+b;
                            
                            if(isValid(row,col,n,m) and mat[row][col]==0)
                            {
                                cnt++;
                            }
                            
                            
                        }
                    }
                    if(cnt>0 and !(cnt&1))
                    {
                        ones++;
                    }
                }
            }
        }
        
        return ones;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends