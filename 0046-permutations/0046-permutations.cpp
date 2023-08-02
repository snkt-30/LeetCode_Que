class Solution
{
    public:
    
    void gen_permute(int ind,vector<int>&a,vector<vector<int>>&ans)
    {
        if(ind==a.size())
        {
            ans.push_back(a);
            return;
        }
        
        for(int i=ind;i<a.size();i++)
        {
            swap(a[i],a[ind]);
            
            gen_permute(ind+1,a,ans);
            
            swap(a[i],a[ind]);
        }
    }
    vector<vector < int>> permute(vector<int> &nums)
    {

        vector<vector<int>>ans;
        
        gen_permute(0,nums, ans);

        return ans;
    }
};