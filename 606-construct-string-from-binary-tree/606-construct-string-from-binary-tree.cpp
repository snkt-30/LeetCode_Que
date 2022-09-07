/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        string str = "";
    void helper(TreeNode *node)
    {
        if (node == nullptr)
            return;

        str += to_string(node->val);
        if (node->left or node->right)
        {
            str += '(';
            helper(node->left);
            str += ')';
        }

        if (node->right)
        {
            str += '(';
            helper(node->right);
            str += ')';
        }
    }
    string tree2str(TreeNode *root)
    {
        if (root == nullptr)
            return "";

        helper(root);
        return str;
    }
};