class Solution {
public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        
// //         vector<int>ans;
        
// //         vector<vector<int>>adj[n];
        
// //         for(auto x:e)
// //         {
// //             int u=x[0];
// //             int v=x[1];
            
// //             adj[u].push_back({v,1});
// //             adj[v].push_back({u,1});
// //         }
        
        
        
// //         for(int i=0;i<n;i++)
// //         {
// //             vector<int>dist(n,INT_MAX);
// //             dist[i]=0;
// //             priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            
// //             pq.push({0,i});
            
// //             while(!pq.empty())
// //             {
// //                 auto x=pq.top();
// //                 pq.pop();
// //                 int node=x.second;
// //                 int node_dist=x.first;
                
// //                 for(auto ele:adj[node])
// //                 {
// //                     int nex_node=ele[0];
// //                     int dis=ele[1];
// //                     if(dist[nex_node]>dist[node]+dis)
// //                     {
// //                         dist[nex_node]=dist[node]+dis;
// //                         pq.push({dist[nex_node],nex_node});
// //                     }
// //                 }
// //             }
// //             int sum=0;
// //             for(int i=0;i<n;i++)
// //             {
// //                 sum+=dist[i];
// //             }
// //             ans.push_back(sum);
// //         }
        
// //         return ans;
//     }
    vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }

    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};