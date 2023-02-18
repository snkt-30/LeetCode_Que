class Solution
{

    private:
        void helper(int ind, vector<int> &ar, int target, vector<vector< int >> &res, vector< int > &ds)
        {
            if (ind == ar.size())
            {
                if (target == 0)
                {
                    res.push_back(ds);
                }
                return;
            }

            if (target >= ar[ind])
            {
                ds.push_back(ar[ind]);
                helper(ind, ar, target - ar[ind], res, ds);

                ds.pop_back();
            }

            helper(ind + 1, ar, target, res, ds);
        }
    public:
        vector<vector < int>> combinationSum(vector<int> &candidates, int target)
        {

            vector<vector < int>> res;

            vector<int> ds;

            helper(0, candidates, target, res, ds);

            return res;
        }
};