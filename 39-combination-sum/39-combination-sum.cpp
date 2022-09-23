class Solution
{
    public:
        void combo(int ind, vector<vector < int>> &ans, vector< int > &ds, vector< int > &ar, int target)
        {

            if (target == 0)
            {
                ans.push_back(ds);
                return;
            }
            if (target < 0)
                return;

            if (ind == ar.size())
                return;
            
            combo(ind + 1, ans, ds, ar, target);	// if i am not consider the current element the move the index

            ds.push_back(ar[ind]);
            combo(ind, ans, ds, ar, target - ar[ind]);	//if i was taking that element then why should i have to move the index coz i  have the unlimited acces of same element
            ds.pop_back();

           	

        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> ds;

        combo(0, ans, ds, candidates, target);
        return ans;
    }
};