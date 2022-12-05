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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          map<int,map<int,multiset<int>>> mp;
        
        queue<pair<TreeNode*,pair<int,int>>> bfs;
        
        bfs.push(make_pair(root,make_pair(0,0)));
        
        while(!bfs.empty())
        {
            auto p=bfs.front();
            bfs.pop();
            
            TreeNode* node=p.first;
            int level=p.second.first;
            int axis=p.second.second;
            
            mp[axis][level].insert(node->val);
            
            if(node->left)
            {
                bfs.push(make_pair(node->left,make_pair(level+1,axis-1)));
            }
            if(node->right)
            {
                bfs.push(make_pair(node->right,make_pair(level+1,axis+1)));
            }
        }
        
        vector<vector<int>>ans;
        
        for(auto x:mp)
        {
            vector<int>col;
            for(auto p:x.second)
               col.insert(col.end(),p.second.begin(),p.second.end());
            
            ans.push_back(col);
        }
        return ans;
    }
};