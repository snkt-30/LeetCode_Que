//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        
        // queue<pair<int,int>> bfs;
        
        // bfs.push(make_pair(0,-1));
        
        // int vis[V]={0};
        
        // vis[0]=1;
        for(int i=0;i<V;i++){
             
        queue<pair<int,int>> bfs;
        
        bfs.push(make_pair(i,-1));
        
        int vis[V]={0};
        
        vis[i]=1;
            
        while(!bfs.empty())
        {
            pair<int,int>temp=bfs.front();
            int node=temp.first;
            int par=temp.second;
            bfs.pop();
            
            for(auto x:adj[temp.first])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    bfs.push(make_pair(x,temp.first));
                }
                else
                  {
                      if(x!=par)
                            return true;
                  }
            }
        }
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