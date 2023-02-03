class DSU{
    
    private:
    vector<int>parent,size;
    
    public:
     DSU(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find_par(int node)
    {
        if(node==parent[node])
            return node;
        
        return parent[node]=find_par(parent[node]);
    }
    
    void Union(int a,int b)
    {
        int par_a=find_par(a);
        int par_b=find_par(b);
        
        if(par_a != par_b)
        {
            if(size[par_a]<size[par_b])
                swap(par_a,par_b);
            
           parent[par_b]=par_a;
            size[par_a]+=size[par_b];
        }
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
         int n=edges.size();
        
          DSU obj(n);
        
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            
            int par_u=obj.find_par(u);
            int par_v=obj.find_par(v);
            
            if(par_u!=par_v)
            {
                obj.Union(u,v);
            }
            else
            {
               return x;
            }
        }
        
        return {};
        
        
        
        
    }
};