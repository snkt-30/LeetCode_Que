class Solution {
public:
    double dp[101][101];
    
    double solve(int p,int i, int j)
    {
        if(i<0 or j<0 or i<j)
        {
            return 0.0;
        }
        
        if(i==0 and j==0)
        {
            return p;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        double left=(solve(p,i-1,j-1)-1)/2.0;
        double right=(solve(p,i-1,j)-1)/2.0;
        
        if(left<0.0)
        {
            left=0.0;
        }
        
        if(right<0.0)
        {
            right=0.0;
        }
        
        return dp[i][j]=left+right;
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
       for(int i=0;i<101;i++)
       {
           for(int j=0;j<101;j++)
           {
               dp[i][j]=-1;
           }
       }
        return  min(1.0, solve(poured,query_row,query_glass));
    }
};