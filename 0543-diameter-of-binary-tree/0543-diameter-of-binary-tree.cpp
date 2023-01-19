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
    
    private:
    
    int daimeter(TreeNode* node)
    {
        if(!node)return 0;
        
        int lh=daimeter(node->left);
        int rh=daimeter(node->right);
        
        int curr=(lh+rh);
        
        dai=max(dai,curr);
        
        return max(lh,rh)+1;
    }
public:
    
    int dai=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
        
        daimeter(root);
        
        return dai;
    }
};