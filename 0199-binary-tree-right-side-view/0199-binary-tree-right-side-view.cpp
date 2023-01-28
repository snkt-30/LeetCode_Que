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
    vector<int> rightSideView(TreeNode* root) {
        
      if(!root)
        return {};
        
        queue<TreeNode*> bfs;
        
        bfs.push(root);
        
        vector<int>ans;
        
        while(!bfs.empty())
        {
            vector<int>temp;
            int n=bfs.size();
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node=bfs.front();
                bfs.pop();
                temp.push_back(node->val);
                
                if(node->left)
                    bfs.push(node->left);
                if(node->right)
                    bfs.push(node->right);
            }
            int r_ele=temp[temp.size()-1];
            ans.push_back(r_ele);
        }
        
        return ans;
    }
};