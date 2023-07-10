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
    int minDepth(TreeNode* root) {
           int ans=10000;
            
            if(!root)
                return 0;
            
            queue<pair<TreeNode*,int>> bfs;
        
        
        bfs.push(make_pair(root,1));
        
        while(!bfs.empty())
        {
            auto x=bfs.front();
            bfs.pop();
            
            TreeNode* node=x.first;
            int depth=x.second;
            
           if(!node->left and !node->right)
           {
               ans=min(ans,depth);
           }
            
            if(node->left)
            {
                bfs.push(make_pair(node->left,depth+1));
            }
            
            if(node->right)
            {
                bfs.push(make_pair(node->right,depth+1));
            }
        }
        
        return ans;
    }
};