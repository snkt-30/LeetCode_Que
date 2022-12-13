class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            ans[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int up_left=INT_MAX;
                int up=ans[i-1][j];
                int up_right=INT_MAX;
                if(j>0)
                {
                   up_left=ans[i-1][j-1]; 
                }
                if(j<m-1)
                {
                    up_right=ans[i-1][j+1];
                }
                ans[i][j]+=matrix[i][j]+min({up_left,up,up_right});
                
            }
        }
        
        int res=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            res=min(res,ans[n-1][i]);
        }
        
        return res;
    }
    
    
    
};