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
    int height(TreeNode* root)
    {
        if(!root)return 0;
        
        int lh= height(root->left);

        int rh=height(root->right);
        
       int ch=abs(lh-rh);
        
        if(ch>1)
        {
            flag=false;
        }
        
        // cout<<root->val<<" "<<lh<<" "<<rh<<" "<<ch<<endl;
        return (max(lh,rh)+1);
    }   
public:     
    bool flag=true;
    
    bool isBalanced(TreeNode* root) {
        
        if(!root)return true;
        
        height(root);
        
        return flag;
        
    }
};