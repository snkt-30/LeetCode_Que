//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{ 
    
    private:
    bool isValid(int nrow,int ncol,int row,int col)
    {
        return (nrow>=0 and ncol>=0 and nrow<row and ncol<col);
    }
    
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        
        
        
        --x;
        --y;
        vector<vector<int>> mat(N,vector<int>(M,0));
        mat[x][y]=1;
        
        
        
        
        queue<pair<int,int>> bfs;
        
        bfs.push(make_pair(x,y));
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        int level=0;
        
        
        while(!bfs.empty())
        {
            int n=bfs.size();
            
            for(int i=0;i<n;i++)
            {
                int row=bfs.front().first;
                int col=bfs.front().second;
                
                bfs.pop();
                
                for(int del=0;del<4;del++)
                {
                    int nrow=row+dx[del];
                    int ncol=col+dy[del];
                    
                    if(isValid(nrow,ncol,N,M) and mat[nrow][ncol]!=1)
                    {
                        mat[nrow][ncol]=1;
                        bfs.push(make_pair(nrow,ncol));
                    }
                }
                
            }
            
            level++;
        }
        
        
        return level-1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends