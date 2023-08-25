class Solution {
    
    bool helper(int k, int i,int j,string a,string b,string c,int dp[101][101][201])
    {
        
        if(k==c.length() and i==a.length() and j==b.length())
            return true;
        
         if(k==c.length())
             return false;
        
        if(i==a.length() and j==b.length())
            return false;
        
            if(dp[i][j][k]!=-1)
               return dp[i][j][k];
        
        if(a[i]==c[k] and b[j]==c[k]){
            return dp[i][j][k]= (helper(k+1,i+1,j,a,b,c,dp) or helper(k+1,i,j+1,a,b,c,dp));
        }
        else if(a[i]==c[k])
        {
            return dp[i][j][k]= helper(k+1,i+1,j,a,b,c,dp);
        }
        else if(b[j]==c[k])
        {
            return dp[i][j][k]=helper(k+1,i,j+1,a,b,c,dp);
        }
        else
        {
            return dp[i][j][k]=false;
        }
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int dp[101][101][201];
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,s1,s2,s3,dp);
    }
};