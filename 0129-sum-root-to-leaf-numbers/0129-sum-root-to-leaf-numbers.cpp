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

    void dfs(TreeNode *root, vector<int> &ds)
    {
        if (!root)
        {
            return;
        }

        if (isleaf(root))
        {
            ds.push_back(root->val);
            res.push_back(ds);

            ds.pop_back();
            return;
        }

        ds.push_back(root->val);
        dfs(root->left, ds);
        dfs(root->right, ds);
        ds.pop_back();
    }
    public:
        vector<vector < int>> res;
    int sumNumbers(TreeNode *root)
    {
        vector<int> ds;

        dfs(root, ds);

        int sum = 0;
        for (auto &x: res)
        {
            int n = x.size();
            int dgt = 0;

            for (int i = 0; i < n; i++)
            {
                dgt = dgt *10 + x[i];
            }

            cout << dgt << endl;

            sum += dgt;
        }

        return sum;
    }
};