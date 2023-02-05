class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                {
                    for(int k=0;k<m;k++)
                    {
                        mat[i][k]=0;
                    }
                    for(int k=0;k<n;k++)
                    {
                        mat[k][j]=0;
                    }
                }
            }
        }
    }
};