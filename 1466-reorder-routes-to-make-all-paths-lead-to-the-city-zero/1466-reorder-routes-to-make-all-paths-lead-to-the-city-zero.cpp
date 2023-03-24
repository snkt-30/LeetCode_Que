#define N 1e5+10

class Solution {
    
    private:
    
    void dfs(int node,int &cnt)
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x] and st.count({node,x}))
            {
                cnt++;
            }
            
            if(!vis[x])
                dfs(x,cnt);
        }
    }
   
public:
      set<pair<int,int>> st;
      bool vis[50005];
      vector<int>adj[50005];       
    int minReorder(int n, vector<vector<int>>& c) {
        
        
        int cnt=0;
          for(auto x:c)
        {
            int u=x[0];
            int v=x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            st.insert(make_pair(u,v));
        }
        
        // vis.resize(N);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,cnt);
        }
        
        return cnt;
        
//        set<pair<int,int>> st;
//         vector<int>vis(n,0);
//         vector<int>adj[n];
        
      
        
        queue<int> bfs;
        
        bfs.push(0);
        
        // int cnt=0;
        
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