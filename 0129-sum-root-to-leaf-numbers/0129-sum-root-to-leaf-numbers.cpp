/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:

        bool isleaf(TreeNode *node)
        {
            return (!node->left and!node->right);
        }

    void dfs(TreeNode *root, vector<int> &ds,string asf)
    {
        if (!root)
        {
            return;
        }

        if (isleaf(root))
        {
            asf=asf+to_string(root->val);
            
            int dgt=stoi(asf);
            
            ds.push_back(dgt);
            
            asf.pop_back();
            return;
        }
        
        
        asf=asf+to_string(root->val);
        dfs(root->left, ds,asf);
        dfs(root->right, ds,asf);
        asf.pop_back();
    }
    public:
     
    int sumNumbers(TreeNode *root)
    {
        vector<int> ds;

        dfs(root, ds,"");
        
        int sum=0;
        for(int i=0;i<ds.size();i++)
        {
            sum+=ds[i];
        }
        return sum;
    }
};