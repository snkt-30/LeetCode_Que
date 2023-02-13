//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    private:
    
    bool dfs(vector<int>adj[],vector<int>&vis,vector<int>&vis_path,vector<int>&check,int node)
    {
        vis[node]=1;
        vis_path[node]=1;
        
        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                if(dfs(adj,vis,vis_path,check,child)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
            else
            {
                if(vis_path[child])
                {
                    check[node]=0;
                    return true;
                }
            }
        }
        
        check[node]=1;
        vis_path[node]=0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>vis_path(V,0);
        
        vector<int>check(V,0);
        
        vector<int>safe_state;
        
        for(int nodes=0;nodes<V;nodes++)
        {
            if(!vis[nodes])
            {
                dfs(adj,vis,vis_path,check,nodes);
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                safe_state.push_back(i);
            }
        }
        return safe_state;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends