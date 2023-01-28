/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    private:
    
    TreeNode* find_lca(TreeNode* node,int n1,int n2)
    {
        
        if(!node)
            return nullptr;
        
        if(node->val==n1 or node->val==n2)
            return  node;
        
        TreeNode* lh=find_lca(node->left,n1,n2);
        TreeNode* rh=find_lca(node->right,n1,n2);
        
        if(!lh and !rh)return nullptr;
        
        if(lh and rh)return node;
        
        if(lh)return lh;
        else if(rh)return rh;
        
        return nullptr;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)return nullptr;
        
        int a=p->val;
        int b=q->val;
        
        TreeNode* ans=find_lca(root,a,b);
        
        return ans;
    }
};