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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        if(!root->left and !root->right)
            return 1;
        
        
        queue<pair<TreeNode*,int>> bfs;
        
        bfs.push(mk(root,1));
        
        long long ans=1;
        
        while(!bfs.empty())
        {
           int n=bfs.size();
            
            long long l=0,r=0;
            
            for(int i=0;i<n;i++)
            {
                auto x=bfs.front();
                bfs.pop();
                
                TreeNode* node=x.first;
                long long ind=x.second;
                
                if(node->left)
                {
                    long long  l_ind=ind*1LL*2;
                    
                    if(l==0)
                    {
                        l=l_ind;
                    }
                    else
                    {
                        r=l_ind;
                    }
                    
                    bfs.push(mk(node->left,l_ind));
                }
                
                if(node->right)
                {
                    long long r_ind=ind*1LL*2+1;
                    
                    if(l==0)
                    {
                        l=r_ind;
                    }
                    else
                    {
                        r=r_ind;
                    }
                    
                    bfs.push(mk(node->right,r_ind));
                }
            }
            
            long long temp=0;
            
            if(r==0 or l==0)
            {
                temp=1;
            }
            else
            {
                temp=r-l+1;
            }
            ans=max(ans,temp);
        }
        
        return ans;
    }
};