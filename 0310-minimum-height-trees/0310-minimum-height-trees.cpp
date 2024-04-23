class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // return{4,5};
        
        if(n==1)
        {
            return {0};
        }
        
       vector<int> adj[n+1],indegree(n+1,0);
        
    
        for(auto x:edges)
        {
            int u= x[0];
            int v= x[1];
            
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> bfs;
        
       for(int i=0;i<n;i++)
       {
           if(indegree[i]==1)
           {
               bfs.push(i);
           }
       }
        vector<int> min_Height_Trees;
        
        cout<<bfs.size()<<endl;
        while(!bfs.empty())
        {
            int outer_edges = bfs.size();
            
            min_Height_Trees.resize(0);
            
            for(int i=0;i<outer_edges;i++)
            {
                int node = bfs.front();
                bfs.pop();
                min_Height_Trees.push_back(node);
                
                for(auto x:adj[node])
                {
                    --indegree[x];
                    if(indegree[x]==1)
                    {
                        bfs.push(x);
                    }
                }
                            
            }
        }
        
        return min_Height_Trees;
        
        
    }
};