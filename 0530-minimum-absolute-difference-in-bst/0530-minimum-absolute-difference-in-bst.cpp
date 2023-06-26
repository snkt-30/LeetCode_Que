
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
public:
    
    int mn=INT_MAX;
    
    TreeNode* prev;
    void pos(TreeNode* node)
    {
        if(!node)
            return ;
        
        pos(node->left);
        
         if(prev!=nullptr)
         {
             mn=min(mn,node->val-prev->val);
         }
        
        prev=node;
        
        pos(node->right);
            
            
            
    }
    int getMinimumDifference(TreeNode* root) {
        
        
     
        pos(root);
        
        return mn;
    }
};