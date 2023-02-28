/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
    
//     void loi(map<vector<int>,int>&mp,map<vector<int>,TreeNode*>&mp2,TreeNode* node)
//     {
//         if(!node)
//             return;
        
//         queue<TreeNode*> bfs;
        
//         bfs.push(node);
//         vector<int> temp;
//         while(!bfs.empty())
//         {
//             TreeNode* root=bfs.front();
//             bfs.pop();
            
//             temp.push_back(root->val);
            
//             if(root->left)
//                 bfs.push(root->left);
            
//             if(root->right)
//                 bfs.push(root->right);
//         }
        
//        mp2[temp]=node;
        
//         mp[temp]++;
//     }
//     map<string,int> mp;
    string solve(TreeNode* node,vector<TreeNode*>&res)
    {
        if(!node)
            return "#";
        
        string s=solve(node->left,res)+','+solve(node->right,res)+','+to_string(node->val);
        
        mp[s]++;
        
        if(mp[s]==2)
            res.push_back(node);
        
        return s;
        
        
    }
    public:
      map<string,int> mp;
        vector<TreeNode*> findDuplicateSubtrees(TreeNode *root) {
            
            if(!root)
                return {};
            
            
            vector<TreeNode*> res;
            
            solve(root,res);
            
            return res;
//             if(!root)
//             {
//                 return {};
//             }
            
//             queue<TreeNode*> bfs;
            
//             map<vector<int>,int> mp;
            
//             map<vector<int>,TreeNode*>mp2;
            
//             bfs.push(root);
            
//             while(!bfs.empty())
//             {
//                 TreeNode* node=bfs.front();
//                 bfs.pop();
                
//                 loi(mp,mp2,node);
                
//                 if(node->left)
//                      bfs.push(node->left);
                
//                 if(node->right)
//                     bfs.push(node->right);
//             }
            
//             vector<TreeNode* > ans;
//             for(auto x:mp)
//             {
//                 if(x.second>1)
//                 {
//                   ans.push_back(mp2[x.first]);
//                 }
//             }
            
//             return ans;
            
            
        }
};