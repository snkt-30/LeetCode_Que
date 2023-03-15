/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isCompleteTree(TreeNode *root)
        {

            if (!root)
                return true;

            queue<TreeNode*> bfs;

            bfs.push(root);

            bool flag = true;

            while (!bfs.empty())
            {
                TreeNode *node = bfs.front();

                bfs.pop();

                if (node->left!=nullptr)
                {
                    if (flag == false)
                        return false;
                    else
                        bfs.push(node->left);
                }
                else
                {
                    flag = false;
                }

                
                if (node->right!=nullptr)
                {
                    if (flag == false)
                        return false;
                    else
                         bfs.push(node->right);
                }
                else
                {
                    flag = false;
                }
            }

            return true;
        }
};