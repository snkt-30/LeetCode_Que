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

#define mk make_pair

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
        {
            return 0;
        }
        
        queue<pair<TreeNode*,pair<int,int>>> bfs;
        
        if(root->left)
        {
            bfs.push(mk(root->left,mk(0,1)));
        }
        
        if(root->right)
        {
            bfs.push(mk(root->right,mk(1,1)));
        }
        
        int ans=INT_MIN;
        
        while(!bfs.empty())
        {
            auto x=bfs.front();
            bfs.pop();
            
            TreeNode* node=x.first;
            int side=x.second.first;
            int len=x.second.second;
            
            cout<<side<<" "<<len<<endl;
            
            if(node->left)
            {
               if(side==0)
               {
                   ans=max(ans,len);
                   bfs.push(mk(node->left,mk(0,1)));
               }
                else
                {
                    bfs.push(mk(node->left,mk(0,len+1)));
                }
            }
            
            if(node->right)
            {
                if(side==1)
                {
                    ans=max(ans,len);
                    bfs.push(mk(node->right,mk(1,1)));
                }
                else
                {
                    bfs.push(mk(node->right,mk(1,len+1)));
                }
            }
            ans=max(ans,len);
        }
        
        return ans;
    }
};