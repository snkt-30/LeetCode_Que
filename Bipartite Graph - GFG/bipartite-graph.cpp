//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    // private:
    
    // bool check(int st,int V,vector<int>ajd[],int col[])
    // {
    //     queue<int>bfs;
        
    //     bfs.push(st);
        
    //     while(!bfs.empty())
    //     {
    //         int node=bfs.front();
    //         bfs.pop();
            
    //         for(auto it:ajd[node])
    //         {
    //             if(col[it]==-1)
    //             {
    //                 bfs.push(it);
    //                 col[it]=!col[node];
    //             }
    //             else
    //             {
    //                 if(col[it]==col[node])
    //                   return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
public:
	bool isBipartite(int V, vector<int>ajd[]){
	   // // Code here
	   
	   int col[V];
	   
	   
	   for(int i=0;i<V;i++)
	   {
	       col[i]=-1;
	   }
	   
	   
	   for(int i=0;i<V;i++)
	   {
	       if(col[i]==-1)
	       {
	         queue<int>bfs;
        
             bfs.push(i);
        
        while(!bfs.empty())
        {
            int node=bfs.front();
            bfs.pop();
            
            for(auto it:ajd[node])
            {
                if(col[it]==-1)
                {
                    bfs.push(it);
                    col[it]=!col[node];
                }
                else
                {
                    if(col[it]==col[node])
                      return false;
                }
            }
        }
	       }
	   }
	   return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends