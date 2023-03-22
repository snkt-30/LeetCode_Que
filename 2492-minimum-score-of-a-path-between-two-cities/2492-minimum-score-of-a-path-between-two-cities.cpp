

class Solution {
    
    private:
    
    int find_par(int node)
    {
        if(par[node]==node)
        {
            return node;
        }
        
        return par[node]=find_par(par[node]);
    }
public:
    
    int par[100005];
    int minScore(int n, vector<vector<int>>& r) {
        
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
        
        int m=r.size();
        
        for(int i=0;i<m;i++)
        {
            int u=r[i][0];
            int v=r[i][1];
            
            int a=find_par(u);
            int b=find_par(v);
            
            par[b]=a;
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
        {
            int node=r[i][0];
            
            if(find_par(node)==find_par(1))
            {
                ans=min(ans,r[i][2]);
            }
        }
        
        return ans;
        
    }
};