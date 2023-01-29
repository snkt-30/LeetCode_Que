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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)return 0;
        queue<pair<TreeNode*,int>> bfs;
        
        bfs.push(make_pair(root,0));
        
        int mx_width=0;
        
        while(!bfs.empty())
        {
            int mn_ind=bfs.front().second;
            
            int n=bfs.size();
            
            int first=0,second=0;
            
            for(int i=0;i<n;i++)
            {
                pair<TreeNode* ,int> temp=bfs.front();
                bfs.pop();
                
                TreeNode* node=temp.first;
                int ind=temp.second;
                
                long long int curr_ind = ind-mn_ind;
                
                if(i==0)
                {
                    first=curr_ind;
                }
                
                if(i==n-1)
                {
                    second=curr_ind;
                }
                
                if(node->left)
                {
                    bfs.push(make_pair(node->left,curr_ind*2+1));
                }
                
                if(node->right)
                {
                    bfs.push(make_pair(node->right,curr_ind*2+2));
                }
            }
            int curr_width=second-first+1;
            
            mx_width=max(mx_width,curr_width);
        }
        
        return mx_width;
        
        
    }
};