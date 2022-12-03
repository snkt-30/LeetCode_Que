class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        
        vector<int>indegeree(n);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegeree[u]++;
            indegeree[v]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegeree[i]==1)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        
        while(!q.empty())
        {
            int s=q.size();
            ans.clear();
            
            for(int i=0;i<s;i++)
            {
                int  node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto x:adj[node])
                {
                    indegeree[x]--;
                    if(indegeree[x]==1)
                        q.push(x);
                }
            }
        }
        
        if(n==1)
            ans.push_back(0);
        
        return ans;
        
//         vector<int>ans(n);
//         for(int i=0;i<n;i++)
//         {
//             queue<pair<int,int>> bfs;
//          vector<int>vis(n,0);
            
//             bfs.push(make_pair(i,0));
//             int h=0;
//             vis[i]=1;
            
//             while(!bfs.empty())
//             {
//                pair<int,int>temp=bfs.front();
//                 bfs.pop();
                
//                 int node=temp.first;
//                 int hei=temp.second;
//                 vis[node]=1;
                
//                 for(auto x:adj[node])
//                 {
//                     if(!vis[x])
//                     {
//                         bfs.push(make_pair(x,hei+1));
//                     }
//                 }
                
//                 h=max(h,hei);
                
//             }            
//                ans[i]=h;  
//         }
        
//         unordered_map<int,vector<int>>mp;
        
//         int mn=INT_MAX;
//         for(int i=0;i<ans.size();i++)
//         {
//             mn=min(mn,ans[i]);
//             mp[ans[i]].push_back(i);
//         }
        
//         vector<int> a;
//         a=mp[mn];
        
//         return a;
        
        
    }
};