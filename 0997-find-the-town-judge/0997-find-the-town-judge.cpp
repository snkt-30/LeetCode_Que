class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        
        vector<int> indegre(n+1,0),outdegr(n+1,0);
        
        for(auto x:trust)
        {
            int u=x[0];
            int v=x[1];
            
            indegre[v]++;
            outdegr[u]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(indegre[i]==n-1 and outdegr[i]==0)
                return i;
            
        }
        return -1;
    }
};