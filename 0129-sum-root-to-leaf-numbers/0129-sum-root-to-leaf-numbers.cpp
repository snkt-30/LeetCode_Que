/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:

        bool isleaf(TreeNode *node)
        {
            return (!node->left and!node->right);
        }

    void dfs(TreeNode *root, string asf, int &sum)
    {
        if (!root)
        {
            return;
        }

        if (isleaf(root))
        {
            asf = asf + to_string(root->val);

            int dgt = stoi(asf);

            sum += dgt;

            asf.pop_back();

            return;
        }
        asf = asf + to_string(root->val);

        dfs(root->left, asf, sum);

        dfs(root->right, asf, sum);

        asf.pop_back();
    }
    public:

        int sumNumbers(TreeNode *root)
        {
            int sum = 0;

            dfs(root, "", sum);

            return sum;
        }
};