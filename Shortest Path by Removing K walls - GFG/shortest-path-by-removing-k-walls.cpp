//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) 
    {
        vector<vector<int>> vis( n, vector<int>( m, -1 ) );
        
        queue< pair< int, pair< int, int > > > q;
        q.push( {k, {0, 0} } );
        vis[0][0] = k;
        
        int ct = -1;
        while( !q.empty() )
        {
            int sz = q.size();
            ct++;
            
            for( int i = 0; i < sz; i++ )
            {
                auto cur = q.front();
                q.pop();
                if( cur.second.first == n - 1 && cur.second.second == m - 1 ) return ct;
                
                for( int ind = 0; ind < 4; ind++ )
                {
                    int newx = cur.second.first + dir[ind][0], newy = cur.second.second + dir[ind][1];
                    
                    if( newx >= 0 && newx <n && newy >= 0 && newy < m )
                    {
                        if( mat[newx][newy] == 0 )
                        {
                            if( vis[newx][newy] == -1 || cur.first > vis[newx][newy] )
                            {
                                q.push( {cur.first, {newx, newy} } );
                                vis[newx][newy] = cur.first;
                            }
                        }
                        else if( cur.first > 0 && cur.first > vis[newx][newy] )
                        {
                            q.push( {cur.first - 1, {newx, newy} } );
                            vis[newx][newy] = cur.first;
                        }
                    }
                }
            }
        }
        
        return -1;
        
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends