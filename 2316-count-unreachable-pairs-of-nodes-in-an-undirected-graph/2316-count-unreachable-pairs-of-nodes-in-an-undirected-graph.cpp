class DSU
{
    public:
        vector<int> parent, size;
    DSU(int n)
    {
       	// rank.resize(n+1,1);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find_par(int a)
    {
        if (a == parent[a]) return a;

        return parent[a] = find_par(parent[a]);
    }

    void Union_by_size(int a, int b)
    {
        int ul_p_a = find_par(a);
        int ul_p_b = find_par(b);

        if (size[ul_p_a] < size[ul_p_b])
            swap(ul_p_a, ul_p_b);

        parent[ul_p_b] = ul_p_a;

        size[ul_p_a] += size[ul_p_b];
    }
};

class Solution
{
    public:
        int vis[100010];
    long long countPairs(int n, vector<vector < int>> &e) {
        
        
        DSU ds(n);
        for(auto x:e)
        {
            int u=x[0];
            int v=x[1];
            
            int a=ds.find_par(u);
            int b=ds.find_par(v);
            
            if(a!=b)
            {
                ds.Union_by_size(a,b);
            }
        }
        
         for(auto x:e)
        {
            int u=x[0];
            int v=x[1];
            
            int a=ds.find_par(u);
            int b=ds.find_par(v);
            
            if(a!=b)
            {
                ds.Union_by_size(a,b);
            }
        }
        
        map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[ds.parent[i]]++;
        }
        
        if(mp.size()==1)
            return 0;
        
        vector<int> s;
        
        for(auto x:mp)
        {
            s.push_back(x.second);
        }
        
        // sort(s.begin().s.end());
        
        for(int i=0;i<n;i++)
        {
            cout<<ds.parent[i]<<" "<<i<<endl;
        }
        vector<int>pr(s.size());
        
        pr[s.size()-1]=s[s.size()-1];
        
        for(int i=s.size()-2;i>=0;i--)
        {
            pr[i]=pr[i+1]+s[i];
        }
        
        long long int ans=0;
        
        for(int i=0;i<s.size()-1;i++)
        {
            long long temp=s[i]*1LL*pr[i+1];
            
            ans+=temp;
        }
        
        return ans; 
    }
};