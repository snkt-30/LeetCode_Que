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
    public:
        bool remove_one(TreeNode *root)
        {

            if (root == nullptr)
                 return false;

             if (!root->left and!root->right)
                 return (root->val == 1);

            bool l = remove_one(root->left);
            bool r = remove_one(root->right);

           	// if (l == false and r == false)
           	// {
           	//     root->left = nullptr;
           	//     root->right = nullptr;
           	//    	// return false;
           	// }
           	// else if (l == false)
           	// {
           	//     root->left = nullptr;
           	//    	// return true;
           	// }
           	// else if (r == false)
           	// {
           	//     root->right = nullptr;
           	//    	// return true;
           	// }
            if (!l)
                root->left = nullptr;
            if (!r)
                root->right = nullptr;

            return (l or r or root->val == 1);
        }
    
    TreeNode* pruneTree(TreeNode *root)
    {

       	// bool flag=remove_one(root);

        if (root == nullptr)
             return nullptr;
        
        bool flag=remove_one(root);
        if(flag)
            return root;

        return nullptr;
    }
};