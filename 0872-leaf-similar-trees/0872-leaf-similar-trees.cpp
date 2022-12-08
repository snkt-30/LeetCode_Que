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
    
   void inorder(TreeNode* node,vector<int>&vi)
    {
        if(!node)
            return;
       
        inorder(node->left,vi);
        
        if(!node->left and !node->right)
            vi.push_back(node->val);
       
        inorder(node->right,vi);
    }    
public:
    vector<int> leaf1,leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 and !root2)
             return true;
        
        if(!root1 or !root2) 
            return false;
        
        inorder(root1,leaf1);
        inorder(root2,leaf2);
         
        return leaf1==leaf2;
    }
};