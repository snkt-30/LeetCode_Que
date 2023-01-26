class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto x:f)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];
            
            adj[u].push_back({v,w});
        }
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<int>dist(n,1e9);
        
        q.push({0,{src,0}});
        dist[src]=0;
        
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            
            int stops=x.first;
            int node=x.second.first;
            int node_dist=x.second.second;
            
            if(stops>k)continue;
            
            for(auto it:adj[node])
            {
                int adj_node = it.first;
                int adj_w = it.second;
                
                if((dist[adj_node] > node_dist + adj_w) and stops<=k)
                {
                    dist[adj_node]=node_dist+adj_w;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        
        if(dist[dst]==1e9)return -1;
        
        return dist[dst];
        
    }
};