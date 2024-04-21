class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n+1];
        
        if(n==1)
        {
            return true;
        }
        
        
        for(auto x:edges)
        {
            int u = x[0];
            int v= x[1];
            
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        queue<int> bfs;
        
        vector<int> vis(n+1,0);
        
        bfs.push(source);
        
        while(bfs.size())
        {
            int src = bfs.front();
            bfs.pop();
            
            vis[src]=true;
            
            for (auto ele : adj[src])
            {
                 if(ele == destination)
                    {
                        return true;
                    } 
                if(!vis[ele])
                {
                    
                    bfs.push(ele);
                }
            }
        }
        return false;
    }
};