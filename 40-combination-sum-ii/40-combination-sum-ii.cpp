class Solution
{
    public:

        void solve(int ind, vector<vector < int>> &ans, vector< int > &ds, vector< int > &ar, int target)
        {
            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }

            for (int i = ind; i < ar.size(); i++)
            {
                if (i > ind and ar[i] == ar[i - 1]) continue;

                if (ar[i] > target) break;

                ds.push_back(ar[i]);
                solve(i + 1, ans, ds, ar, target - ar[i]);
                ds.pop_back();
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());

        vector<vector < int>> ans;
        vector<int> ds;

        solve(0, ans, ds, candidates, target);
        return ans;
    }
};