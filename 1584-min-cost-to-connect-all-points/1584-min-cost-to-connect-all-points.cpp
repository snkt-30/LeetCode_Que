class Solution {
    
public:
    
      vector<int>parent;
    vector<int>sz;
    Solution()
    {
        parent.resize(1001);
        sz.resize(1001);
        for(int i=0;i<=1000;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }
    
    
    int find_par(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        
       return parent[node]=find_par(parent[node]);
    }
    
    void Union(int a,int b)
    {
        int a_par=find_par(a);
        int b_par=find_par(b);
        
        if(a_par!=b_par)
        {
            if(sz[a_par]<sz[b_par])
            {
                swap(a_par,b_par);
            }
            
            sz[a_par]+=sz[b_par];
            parent[b_par]=a_par;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& pnt) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        int n=pnt.size();
        
        
        for(int i=0;i<n;i++)
        {
            int x=pnt[i][0];
            int y=pnt[i][1];
            for(int j=i+1;j<n;j++)
            {
                int a=pnt[j][0];
                int b=pnt[j][1];
                int  dist=abs(abs(x-a)+abs(y-b));
                
                pq.push(make_pair(dist,make_pair(i,j)));
            }
        }
        
        int ans=0;
        
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            
            int u=x.second.first;
            
            int v=x.second.second;
            
            if(find_par(u)!=find_par(v))
            {
                ans+=x.first;
                Union(u,v);
            } 
        }
        
        return ans;
    }
};