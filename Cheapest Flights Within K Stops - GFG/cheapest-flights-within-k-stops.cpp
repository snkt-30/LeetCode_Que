//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        
        vector<pair<int,int>> adj[n];
        
        for(auto x:flights)
        {
            int u=x[0];
            int v=x[1];
            int w=x[2];
            
            adj[u].push_back({v,w});
        }
        
        queue<pair<int,pair<int,int>>> q;
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        q.push({0,{src,0}});
        
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
                int adj_node=it.first;
                int adj_node_dist=it.second;
                
                if(node_dist+adj_node_dist < dist[adj_node] and stops <= k)
                {
                    dist[adj_node]=node_dist+adj_node_dist;
                    
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends