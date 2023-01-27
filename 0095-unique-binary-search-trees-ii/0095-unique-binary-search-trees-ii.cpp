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

    vector<vector<int>>store;
    TreeNode* make_Bst(TreeNode* node,int val)
    {
        if(!node)
        {
            return new TreeNode(val);
        }

        if(node->val > val)
        {
            node->left=make_Bst(node->left,val);
        }
        else
        {
            node->right=make_Bst(node->right,val);
        }

        return node;
    }
  map<vector<int>,TreeNode*> track;
    void lot(TreeNode* node)
    {
        queue<TreeNode* >bfs;
      bfs.push(node);

        vector<int> temp;

        while(!bfs.empty())
        {
            TreeNode* root=bfs.front();
            temp.push_back(root->val);
              bfs.pop();

              if(root->left)
                bfs.push(root->left);

              if(root->right)
                bfs.push(root->right);
        }

       track[temp]=node;

    }

    void permute(vector<int>&ar,int n,int ind)
    {
       
       if(ind==n)
       {
           store.push_back(ar);
           return;
       }

        for(int i=ind;i<n;i++)
        {
            swap(ar[i],ar[ind]);

            permute(ar,n,ind+1);

            swap(ar[i],ar[ind]);
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        
      
        if(n==1)
        {
            TreeNode* node=new TreeNode(n);
            return {node};
        }

        vector<int> ar;
        for(int i=1;i<=n;i++)
        {
            ar.push_back(i);
        }

        permute(ar,n,0);

        for(int i=0;i<store.size();i++)
        {
            vector<int>temp=store[i];

            TreeNode* node=nullptr;
            for(int i=0;i<temp.size();i++)
            {
                node=make_Bst(node,temp[i]);
            }
            lot(node);
        }

        vector<TreeNode* >ans;

        for(auto x:track)
        {
            ans.push_back(x.second);
        }

        return ans;


    }
};