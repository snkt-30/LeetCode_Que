class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pr) {
        
        
        
        vector<int>indegree(nc);
        
        vector<int> adj[nc];
        
        for(auto x:pr)
        {
            int u=x[0];
            int v=x[1];
            
            adj[u].push_back(v);
            
            indegree[v]++;
        }
        
        queue<int>bfs;
        
        // vector<int> courses_can_take;
        
        for(int i=0;i<nc;i++)
        {
            if(indegree[i]==0)
            {
                bfs.push(i);
            }
            
        }
        
        int cnt=0;
        
        while(!bfs.empty())
        {
            int node=bfs.front();
            bfs.pop();
            
            cnt++;
            
            // courses_can_take.push_back(node);
            
            for(auto x:adj[node])
            {
                indegree[x]--;
                
                if(indegree[x]==0)
                {
                    bfs.push(x);
                }
            }
        }
       
        return (cnt==nc);
    }
};