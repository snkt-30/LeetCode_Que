class Solution
{
    public:
        string longestPalindrome(string s)
        {

            int n = s.length();

            vector<vector < int>> dp(n, vector<int> (n, 0));

            int r = 0, c = 0;
            int len = 0;

            for(int g=0;g<n;g++)
            {
                for(int i=0,j=i+g;j<n;i++,j++)
                {
                    if(g==0)
                    {
                        dp[i][j]=1;
                    }
                    else if(g==1)
                    {
                        if(s[i]==s[j])
                        {
                            dp[i][j]=1;
                        }
                    }
                    else
                    {
                        if(s[i]==s[j] and dp[i+1][j-1]==1)
                        {
                            dp[i][j]=1;
                        }
                    }
                    
                    if(dp[i][j]==1)
                    {
                        int t_len=j-i;
                        
                        if(t_len>len)
                        {
                            len=t_len;
                            r=i;
                            c=j;
                        }
                    }
                }
            }
            
            string res="";
            
            for(int i=r;i<=c;i++)
            {
                res+=s[i];
            }
            return res;
        }
};