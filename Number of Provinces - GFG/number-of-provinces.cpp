//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DSU{
 public:
    vector<int>parent,sizes;
    
    DSU(int n){
        sizes.resize(n+1,1);
        
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find_par(int node){
        if(node==parent[node])return node;
        
        return parent[node]=find_par(parent[node]);
    }
    
    void Union_size(int a,int b) {
        int ul_a=find_par(a);
        int ul_b=find_par(b);
        
        if(ul_a==ul_b)return ;
        else
        {
            if(sizes[ul_a]<sizes[ul_b])
            {
                swap(ul_a,ul_b);
            }
            parent[ul_b]=ul_a;
            sizes[ul_a]+=sizes[ul_b];
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>>&adj, int V) {
        // code here
        
     int n=adj.size();
     int m=adj[0].size();
     
     DSU ds(V);
     
     for(int i=0;i<V;i++)
     {
         for(int j=0;j<V;j++)
         {
             if(adj[i][j]==1)
             {
                 ds.Union_size(i,j);
             }
         }
     }
      
      int ans=0;
      
      for(int i=0;i<V;i++)
      {
          if(ds.parent[i]==i)ans++;
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends