//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(int node,vector<int>&vis,int par,vector<int>adj[])
    {
        vis[node]=1;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
               if (dfs(x,vis,node,adj)==true)
                      return true;
            }
            else
            {
                if(par!=x)return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i] and dfs(i,vis,-1,adj))
               return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends