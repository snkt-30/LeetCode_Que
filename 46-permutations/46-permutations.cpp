class Solution
{
    public:

        void gen_permute(int ind, vector<int> &ar, vector< vector< int>> &ans)
        {
            if(ind==ar.size())
            {
                ans.push_back(ar);
                return;
            }
            for(int i=ind;i<ar.size();i++)
            {
                swap(ar[i],ar[ind]);
                gen_permute(ind+1,ar,ans);
                swap(ar[i],ar[ind]);
            }
        }
    vector<vector < int>> permute(vector<int> &nums)
    {

        vector<vector < int>> ans;
        // vector<int> ds;
        // int freq[nums.size()];


        gen_permute(0,nums, ans);

        return ans;
    }
};