//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& f, int n, int k) {
        // code her
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> bfs;
        
        vector<int>dist(n+1,INT_MAX);
        
        dist[k]=0;
        
        vector<vector<int>> adj[n+1];
        
        for(auto t:f)
        {
            int u=t[0];
            int v=t[1];
            int w=t[2];
            
            adj[u].push_back({v,w});
        }
        
        bfs.push(make_pair(0,k));
        
        while(!bfs.empty())
        {
            auto x=bfs.top();
            bfs.pop();
            
            int node=x.second;
            int wt=x.first;
            
            for(auto n:adj[node])
            {
                int nex_node = n[0];
                int nex_wt = n[1];
                
                if(dist[nex_node] > dist[node] + nex_wt)
                {
                    dist[nex_node] = dist[node] + nex_wt;
                    
                    bfs.push(make_pair(dist[nex_node],nex_node));
                }
            }
    
        }
       int mx=0;
        for(int i=1;i<=n;i++)
        {
            int m=dist[i];
            
            mx=max(mx,m);
        }
        
        
        return mx==INT_MAX?-1:mx;
        
        
        
       
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends