//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
    vector<bool>vis(V + 1, false);
    
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			queue<pair<int,int>> bfs;
			
			bfs.push({i,-1});
			
			vis[i]=true;
			
			while(!bfs.empty())
			{
			    auto x=bfs.front();
			    bfs.pop();
			    
			    int node=x.first;
			    int par=x.second;
			    
			    for(auto it:adj[node])
			    {
			        if(!vis[it])
			        {
			            vis[it]=true;
			            bfs.push(make_pair(it,node));
			        }
			        else
			        {
			            if(it!=par)return true;
			        }
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