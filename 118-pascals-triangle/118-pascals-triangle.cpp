class Solution
{
    public:
        vector<vector < int>> generate(int n)
        {
            vector<vector < int>> ans;

            for (int i = 0; i < n; i++)
            {
                vector<int> temp(i + 1);
                if (i == 0)
                {
                    temp[0] = 1;
                    ans.push_back(temp);
                    continue;
                }
                if (i == 1)
                {
                    temp[0] = temp[1] = 1;
                    ans.push_back(temp);
                    continue;
                }
                temp[0] = temp[i] = 1;
                for (int j = 1; j < i; j++)
                {
                    temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
                ans.push_back(temp);
            }
            return ans;
        }
};