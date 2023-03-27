
#define mk make_pair
class Solution
{

    public:

        int dp[210][210];
    int minPathSum(vector<vector < int>> &a)
    {

        int n = a.size();
        int m = a[0].size();

        dp[0][0] = a[0][0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + a[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            dp[0][i] = dp[0][i - 1] + a[0][i];
        }

       	//             for(int i=0;i < n;i++)
       	//         {
       	//             for(int j=0;j < m;j++)
       	//             {
       	//                 cout<<dp[i][j]<<" ";
       	//             }
       	//             cout<<endl;
       	//         }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
            }
        }

        return dp[n - 1][m - 1];
    }
};