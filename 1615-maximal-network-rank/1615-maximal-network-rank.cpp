class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> ind(n+1,0);
        
        vector<vector<int>> mat(n+1,vector<int>(n+1,0));
        
        for(auto x:roads)
        {
            int u=x[0];
            int v=x[1];
            
            mat[u][v]=1;
            mat[v][u]=1;
            
            ind[u]++;
            ind[v]++;
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int a=ind[i];
                    int b=ind[j];
                    
                    int sum=a+b;
                    
                    if(mat[i][j]==1)
                    {
                        sum-=1;
                    }
                    
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};