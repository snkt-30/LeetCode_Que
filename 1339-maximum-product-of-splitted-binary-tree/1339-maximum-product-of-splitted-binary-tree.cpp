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
const int mod=1e9+7;
class Solution {
    private:
    int dfs(TreeNode* node)
    {
        if(!node)
            return 0;
        
        int lh=dfs(node->left);
        int rh=dfs(node->right);
        
        node->val=node->val+lh+rh;
        
        return node->val;
    }
public:
    int maxProduct(TreeNode* root) {     
        if(!root)return 0;
        queue<TreeNode* > bfs;
        bfs.push(root);
        long long  total=0;  
        while(!bfs.empty())
        {
            TreeNode* node=bfs.front();
            bfs.pop();
            total+=node->val;
            
            if(node->left)bfs.push(node->left);
            if(node->right)bfs.push(node->right);
        }    
         TreeNode* Sumtree=root;    
        dfs(Sumtree);        
        vector<int>vi;         
        queue<TreeNode* > s;        
        s.push(Sumtree);
        while(!s.empty())
        {
            TreeNode* node=s.front();
            s.pop();
            
            vi.push_back(node->val);
            if(node->left)s.push(node->left);
            if(node->right)s.push(node->right);
        } 
        long long  ans=0;       
        for(int i=0;i<vi.size();i++)
        {
            long long b=vi[i];
            ans=max(ans,((total-b)*b));
        }       
        ans=ans%mod;
        return ans;
      
    }
};