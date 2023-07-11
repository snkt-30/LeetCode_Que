/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void mark_parent(TreeNode* node, unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* target)
    {
        queue<TreeNode*>bfs;
        bfs.push(node);
        
        while(!bfs.empty())
        {
            TreeNode* curr=bfs.front();
            bfs.pop();
            
            if(curr->left)
            {
                parent_track[curr->left]=curr;
                bfs.push(curr->left);
            }
            
            if(curr->right)
            {
                parent_track[curr->right]=curr;
                bfs.push(curr->right);
            }
                                
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent_track;
        
        mark_parent(root,parent_track,target);
        
        unordered_map<TreeNode*, bool> visited;
        
        queue<TreeNode* > bfs;
        
        bfs.push(target);
        
        visited[target]=true;
        
        int curr_level=0;
        
        while(!bfs.empty())
        {
            int sz=bfs.size();
            
            if(curr_level++==k)
            {
                break;
            }
            
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=bfs.front();
                bfs.pop();
                
                if(node->left and !visited[node->left])
                {
                    bfs.push(node->left);
                    visited[node->left]=true;
                }
                
                if(node->right and !visited[node->right])
                {
                    bfs.push(node->right);
                    visited[node->right]=true;
                }
                
                if(parent_track[node] and !visited[parent_track[node]])
                {
                    bfs.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                }
            }
        }
        
        vector<int>res;
        
        while(!bfs.empty())
        {
            TreeNode* node=bfs.front();
            bfs.pop();
            
            res.push_back(node->val);
        }
        
        return res;
    }
};