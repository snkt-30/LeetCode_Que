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
    TreeNode* build(TreeNode* root,int ind)
    {
        if(!root)
        {
            return new TreeNode(ind);
        }
        
        if(root->val > ind)
        {
            root->left=build(root->left,ind);
        }
        else if(root-> val < ind)
        {
            root->right=build(root->right,ind);
        }
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    TreeNode* root=nullptr;
        
        for(int i=0;i<preorder.size();i++)
        {
            int val=preorder[i];
            
            root=build(root,val);
        }
        
        return root;
    }
};