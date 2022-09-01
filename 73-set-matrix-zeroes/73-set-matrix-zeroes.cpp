class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        if(q.empty())
        {
            return;
        }
        
    while(!q.empty())
    {
        pair<int,int> cor=q.front();
        q.pop();
        int x=cor.first;
        int y=cor.second;
        
        for(int i=0;i<n;i++)
        {
            matrix[i][y]=0;
        }
        for(int i=0;i<m;i++)
        {
            matrix[x][i]=0;
        }
    }
        
        return;
        
    }
};