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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        if(!root)
            return {};
        vector<vector<int>> res;
        
        queue<TreeNode* > bfs;
        
        bfs.push(root);
        
        bool flag=true;
        while(!bfs.empty())
        {
            int n=bfs.size();
            vector<int>temp;
            
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
            
            if(!flag)
                reverse(temp.begin(),temp.end());
            flag=!flag;
            
            res.push_back(temp);
        }
        
        return res;
    }
};