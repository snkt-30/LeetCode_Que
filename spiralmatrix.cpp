#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 

    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    { 
        int frow=0,lrow=r-1,fcol=0,lcol=c-1;
        vector<int> ans;
        int total=r*c,cnt=0;
        
        while(frow<=r and lrow>=0 and fcol<=c and lcol>=0)
        {
           // first row
            for(int col=fcol;cnt<total and col<=lcol;col++)
            {
                int x=matrix[frow][col];
                ans.push_back(x);
                cnt++;
            }
            ++frow;
            
            // last column print
             for(int row=frow;cnt<total and row<=lrow;row++)
            {
                int x=matrix[row][lcol];
                ans.push_back(x);
                cnt++;
            }
            --lcol;
            
            // last row print
             for(int col=lcol;cnt<total and col>=fcol;col--)
            {
                int x=matrix[lrow][col];
                ans.push_back(x);
                cnt++;
            }
            --lrow;
            // first colprint
             for(int row=lrow;cnt<total and row>=frow;row--)
            {
                int x=matrix[row][fcol];
                ans.push_back(x);
                cnt++;
                
            }
            ++fcol;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends