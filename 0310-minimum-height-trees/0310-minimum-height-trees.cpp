#define pb emplace_back
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        
        vector<int>ind(n);
        vector<int>adj[n];
        
        if(n==1)
            return {0};
        
        for(auto x:e)
        {
            int u=x[0];
            int v=x[1];
            
            adj[u].pb(v);
            adj[v].pb(u);
            ind[v]++;
            ind[u]++;
        }
        
        vector<int>ans;
        queue<int>bfs;
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]==1)
                bfs.push(i);
        }
        
        while(!bfs.empty())
        {
            int sz=bfs.size();
            ans.clear();
            
            for(int i=0;i<sz;i++)
            {
                int node=bfs.front();
                bfs.pop();
                ans.push_back(node);
                
                for(auto x:adj[node])
                {
                    ind[x]--;
                    if(ind[x]==1)
                        bfs.push(x);
                }
            }
        }
        return ans;
    }
};