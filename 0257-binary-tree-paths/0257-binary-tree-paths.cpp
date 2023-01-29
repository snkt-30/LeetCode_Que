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
    
    bool isleaf(TreeNode* node)
    {
        return (!node->left and !node->right);
    }
    
    void helper(TreeNode* node,vector<string>&res,string s)
    {
        if(!node)return ;
        
        if(isleaf(node))
        {
            int val=node->val;
            
            s+=to_string(val);
            
            res.push_back(s);
            
            return;
        }
        else
        {
            int val=node->val;
            
            s+=to_string(val);
            s+="->";
        }
        
        helper(node->left,res,s);
        helper(node->right,res,s);
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(!root)
            return {};
        
        vector<string> res;
        
        helper(root,res,"");
        
        return res;
    }
};