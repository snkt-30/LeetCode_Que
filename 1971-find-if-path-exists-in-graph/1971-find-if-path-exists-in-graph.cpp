class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        
        queue<int>q;
        q.push(source);
        
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n);
        
        vis[source]=1;
        while(!q.empty())
        {
           int node=q.front();
            q.pop();
            vis[node]=1;
            
            if(node==destination)return true;
            for(auto x:adj[node])
            {
                if(!vis[x])
                    q.push(x);
            }
        }
        return false;
    }
};