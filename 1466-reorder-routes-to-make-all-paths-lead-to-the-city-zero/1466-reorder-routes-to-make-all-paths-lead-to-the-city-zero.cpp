class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        
       set<pair<int,int>> st;
        vector<int>vis(n,0);
        vector<int>adj[n];
        
        for(auto x:c)
        {
            int u=x[0];
            int v=x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            st.insert(make_pair(u,v));
        }
        
        queue<int> bfs;
        
        bfs.push(0);
        
        int cnt=0;
        
        while(!bfs.empty())
        {
            int node=bfs.front();
            bfs.pop();
            
            vis[node]=true;
            
            for(auto x:adj[node])
            {
                 
                if(!vis[x] and st.count(make_pair(node,x)))
                {
                    cnt++;
                   
                }
                
                if(!vis[x])
                    bfs.push(x);
            }
        }
        
        return cnt;
    }
};