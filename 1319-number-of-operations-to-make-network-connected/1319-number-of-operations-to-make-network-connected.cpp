class DSU{

	
 public:
    vector<int>parent,size;
	DSU(int n)
	{
		// rank.resize(n+1,1);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			parent[i] = i;
		}
	}

	int find_par(int a)
	{
		if(a==parent[a])return a;

		return parent[a] = find_par(parent[a]);
	}

	void Union_by_size(int a,int b)
	{
		int ul_p_a = find_par(a);
		int ul_p_b = find_par(b);
        
        if(size[ul_p_a]<size[ul_p_b])
            swap(ul_p_a,ul_p_b);
        
        parent[ul_p_b]=ul_p_a;
        
        size[ul_p_a]+=size[ul_p_b];
	}
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        
        
        DSU ds(n);
        
        int cnt=0;
        for(auto x:c)
        {
            int u=x[0];
            int v=x[1];
            
            int a=ds.find_par(u);
            int b=ds.find_par(v);
            
            if(a==b)
            {
                cnt++;
            }
            else
            {
                ds.Union_by_size(u,v);
            }
        }
        
        int comp=0;
        
        for(int i=0;i<n;i++)
        {
            if(i==ds.parent[i])
            {
                comp++;
            }
        }
        
        --comp;
        
        if(cnt<comp)
            return -1;
        
        else
            return comp;
        
        
    }
};