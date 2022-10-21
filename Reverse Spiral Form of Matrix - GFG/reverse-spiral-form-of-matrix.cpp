//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int f_row=0,l_row=R-1, f_col=0,l_col=C-1;
        
        int  cnt=R*C;
        vector<int>ans;
        while(f_row<R and l_row>=0 and f_col<C and l_col>=0 )
        {
            for(int row=f_col;row<=l_col and cnt>0;row++)
            {
                ans.push_back(a[f_row][row]);
                cnt--;
            }
            f_row++;
            
            for(int col=f_row;col<=l_row and cnt>0 ;col++)
            {
                ans.push_back(a[col][l_col]);
                cnt--;
            }
            l_col--;
            
            for(int row=l_col;row>=f_col and cnt>0;row--)
            {
                ans.push_back(a[l_row][row]);
                cnt--;
            }
            l_row--;
            
            for(int col=l_row;col>=f_row and cnt>0 ;col--)
            {
                ans.push_back(a[col][f_col]);
                cnt--;
            }
            f_col++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends