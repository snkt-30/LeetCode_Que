//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& req) {
	    // Code here
	    
	    vector<int>adj[V];
	    
	    for(auto x:req)
	    {
	        adj[x.second].push_back(x.first);
	    }
	    
	    int indegree[V]={0};
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    queue<int>bfs;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        {
	            bfs.push(i);
	        }
	    }
	    
	    vector<int>topo;
	    
	    while(!bfs.empty())
	    {
	        int node=bfs.front();
	        bfs.pop();
	        topo.push_back(node);
	        
	        for(auto x:adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	            {
	                bfs.push(x);
	            }
	        }
	    }
	    
	    
	    return topo.size()==V;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends