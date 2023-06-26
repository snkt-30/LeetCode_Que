
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
    
    void pos(TreeNode* node, vector<int>& v)
    {
        if(!node)
            return ;
        
        pos(node->left,v);
        
        v.push_back(node->val);
        
        pos(node->right,v);
            
            
            
    }
    int getMinimumDifference(TreeNode* root) {
        
        
       vector<int>ans;
        
        pos(root,ans);
        
        int res=INT_MAX;
        
        for(int i=1;i<ans.size();i++)
        {
            res=min(res,ans[i]-ans[i-1]);
        }
        
        return res;
    }
};