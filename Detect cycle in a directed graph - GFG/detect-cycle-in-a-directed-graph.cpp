//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    private:
    
    bool dfs(vector<int>adj[],int vis[],int pv[],int node)
    {
        vis[node]=1;
        pv[node]=1;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                if(dfs(adj,vis,pv,x)==true)
                    return true;
            }
            else if(pv[x])
            {
                return true;
            }
        }
        
        pv[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int vis[V]={0};
        int path_vis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,path_vis,i)==true)
                return true;
            }
        }
        
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends