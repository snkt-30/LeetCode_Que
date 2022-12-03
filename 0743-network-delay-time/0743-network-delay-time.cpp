#define inf INT_MAX

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<int>>adj[n+1];
        
        for(int i=0;i<times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            
            adj[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push(make_pair(0,k));
        
        vector<int>dist(n+1,inf);
        
        dist[k]=0;
        
        while(!pq.empty())
        {
            pair<int,int>temp=pq.top();
            pq.pop();
            
            int node=temp.second;
            int node_dist=temp.first;
            
            for(auto x:adj[node])
            {
                int adj_node=x[0];
                int adj_node_dist=x[1];
                
                if(dist[adj_node]>node_dist+adj_node_dist)
                {
                    dist[adj_node]=node_dist+adj_node_dist;
                    pq.push(make_pair(dist[adj_node],adj_node));
                }
            }
        }
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)return -1;
            
            // cout<<dist[i]<<endl;
            
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};