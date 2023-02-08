class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        
        // its simple let considere the pair as u and v where there is directed edge form u to v
        // now as we simplified this will form a directed graph now as the ques ask finish course 
        // means that can we form a  topological sort or not. so the problem break down into that 
        // the graph contain cycle or not . if it contain cycle there the topological sort is not 
        // is not possible bcoz the element is not conitain whole vertex. so just return if 
        // if size of topo array is not equal to numCourses the false else true;
        
        
     vector<int> adj[n];
      vector<int> ind(n,0);
        
        for(auto x:pr)
        {
            int u=x[0];
            int v=x[1];
            
            ind[v]++;
            
            adj[u].push_back(v);
        }
        
        queue<int> bfs;
        
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
                bfs.push(i);
        }
        
        int cnt=0;
        
        while(!bfs.empty())
        {
            int node=bfs.front();
            bfs.pop();
            
            cnt++;
            
            for(auto x:adj[node])
            {
                ind[x]--;
                
                if(ind[x]==0)
                    bfs.push(x);
            }
        }
        
        return cnt==n;
        
        
    }
};