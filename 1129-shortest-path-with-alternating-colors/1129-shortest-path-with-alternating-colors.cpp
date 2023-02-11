class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        
        vector<vector<pair<int,int>>> g(n);
        
        for(auto edge:redEdges)
        {
            g[edge[0]].push_back(make_pair(edge[1],0));
        }
        
         for(auto edge:blueEdges)
        {
            g[edge[0]].push_back(make_pair(edge[1],1));
        }
        
        queue<pair<int,int>> q;
        
        q.push(make_pair(0,0));
        q.push(make_pair(0,1));
        
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        
        dist[0][0]=0;
        dist[0][1]=0;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            
            for(auto adj:g[node])
            {
                int adj_node=adj.first;
                int adj_node_color=adj.second;
                
                if(dist[adj_node][adj_node_color]==INT_MAX and adj_node_color!=color)
                {
                    dist[adj_node][adj_node_color]=dist[node][color]+1;
                    q.push(adj);
                }
            }
        }
        
        vector<int> res(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(dist[i][0]!=INT_MAX or dist[i][1]!=INT_MAX)
            {
                res[i]=min(dist[i][0] , dist[i][1]);
            }
        }
        return res;
        
        
    }
};