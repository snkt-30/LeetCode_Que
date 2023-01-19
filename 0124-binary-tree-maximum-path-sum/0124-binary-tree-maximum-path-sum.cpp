/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int sum(TreeNode* node)
    {
        if(!node)return 0;
        
        int lh=max(0,sum(node->left));
        int rh=max(0,sum(node->right));
        
        max_sum=max(max_sum,node->val+lh+rh);

        
        return max(lh,rh)+node->val;
    }
public:
    
    int max_sum=INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        
        if(!root)return 0;
        sum(root);
        return max_sum;
    }
};