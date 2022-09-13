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
    
    void inorder(TreeNode* root,vector<int>&ds)
    {
        if(!root)
            return;
        
        inorder(root->left,ds);
        ds.push_back(root->val);
        inorder(root->right,ds);
    }
    
   void build_GT(TreeNode* root,vector<int>&ds,unordered_map<int,int>&mp)
    {
       if(!root)
           return;
       
       build_GT(root->left,ds,mp);
       int x=root->val;
       int ind=mp[x];
       root->val=ds[ind];
       build_GT(root->right,ds,mp);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        
        if(root==nullptr)
            return nullptr;
        vector<int>ds;
        
        inorder(root,ds);
        unordered_map<int,int> mp;
        
        for(int i=0;i<ds.size();i++)
        {
            mp[ds[i]]=i;
        }
        for(int i=ds.size()-2;i>=0;i--)
        {
            ds[i]=ds[i]+ds[i+1];
        }
        
        build_GT(root,ds,mp);
        return root;
        
    }
};