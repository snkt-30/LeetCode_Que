//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define inf INT_MAX
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        // vector<int> v[V];
        
      set<pair<int,int>>st;
      
      st.insert(make_pair(0,S));
      
      vector<int> dist(V,inf);
      
      dist[S]=0;
      
      while(!st.empty())
      {
          pair<int,int>temp=*st.begin();
          st.erase(temp);
          
          int prev=temp.second;
          int pre_dist=temp.first;
          
          for(auto x:adj[prev])
          {
              int next=x[0];
              int next_dist=x[1];
              
              if(dist[next]>pre_dist+next_dist)
              {
                 if(dist[next]!=INT_MAX)
                   st.erase({dist[next],next});
                   
                  dist[next]=pre_dist+next_dist;
                  
                  st.insert(make_pair(dist[next],next));
              }
          }
      }
      
      return dist;
    }    
      
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends