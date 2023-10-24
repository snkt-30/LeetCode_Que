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
    vector<int> largestValues(TreeNode* root) {
        
        
        if(!root)
        {
            return {};
        }
        vector<int>ans;

        
        queue<TreeNode* > bfs;
        
        bfs.push(root);
        
        while(!bfs.empty())
        {
            int n=bfs.size();
            
            int mx=INT_MIN;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node=bfs.front();
                bfs.pop();
                
                mx=max(mx,node->val);
                
                if(node->left)
                {
                    bfs.push(node->left);
                }
                
                if(node->right)
                {
                    bfs.push(node->right);
                }
            }
            ans.push_back(mx);
        }
        
        return ans;
    }
};