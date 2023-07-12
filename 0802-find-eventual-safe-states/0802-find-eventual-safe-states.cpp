class Solution {
    
    set<int> result;
    bool dfs(int node,vector<int>&path_visited,vector<int>&visited,vector<vector<int>>& graph)
    {
        path_visited[node]=1;
        visited[node]=1;
        
        for(auto adj_node:graph[node])
        {
            if(!visited[adj_node])
            {
                if(dfs(adj_node,path_visited,visited,graph)==false)
                {
                    return false;
                }
            }
            else
            {
                if(path_visited[adj_node]==true)
                {
                    return false;
                }
            }
        }
        path_visited[node]=false;
        result.insert(node);
        
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        
        vector<int>path_visited(n,0);
        
        vector<int> visited(n,0);
        
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,path_visited,visited,graph);
            }
        }
        
      for(auto x:result)
      {
          res.push_back(x);
      }
        
        return res;
       
    }
};