//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class DSU{
    
    private:
    vector<int>parent,sizes;
    
    public:
    
    DSU(int n) {
        parent.resize(n+1);
        sizes.resize(n+1,1);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find_par(int a) {
        if(a==parent[a])return a;
        
        return parent[a]=find_par(parent[a]);
    }
    
    void Union_size(int a,int b){
        a=find_par(a);
        b=find_par(b);
        
        if(a==b)return;
        else
        {
            if(sizes[a]<sizes[b])
            {
                swap(a,b);
            }
            parent[b]=a;
            sizes[a]+=sizes[b];
        }
    }
    
};
class Solution {
    bool isValid(int row,int col,int n,int m)
    {
        return row>=0 and row<n and col>=0 and col<m;
    }
  public:
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &p) {
        // code here
        
    DSU ds (n * m);
    
    int vis[n][m];
    memset(vis,0,sizeof vis);
    
    vector<int>ans;
    
    int cnt=0;
    
    for(auto x:p)
    {
        int a=x[0];
        int b=x[1];
        
        if(vis[a][b]==1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[a][b]=1;
        cnt++;
             
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
             
             
             for(int i=0;i<4;i++)
             {
                 int nrow=a+dx[i];
                 int ncol=b+dy[i];
                 
                 if(isValid(nrow,ncol,n,m))
                 {
                     if(vis[nrow][ncol]==1)
                     {
                         int node=a*m+b;
                         int newnode=nrow*m+ncol;
                         
                         if(ds.find_par(node)!=ds.find_par(newnode))
                         { 
                             cnt--;
                             ds.Union_size(node,newnode);
                         }
                     }
                 }
             }
             ans.push_back(cnt);
       }
       
    return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends