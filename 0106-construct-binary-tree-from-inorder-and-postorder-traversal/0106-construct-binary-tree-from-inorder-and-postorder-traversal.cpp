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
    
//     TreeNode* build(vector<int>&inorder,vector<int>&post,int lh,int rh,int rootidx)
//     {
       
//         if(lh>rh)
//         {
//             return NULL;
//         }
//          int pivot=lh;
//         while(inorder[pivot]!=post[rootidx])
//             pivot++;
        
//         rootidx--;
//         TreeNode* n=new TreeNode(inorder[pivot]);
        
//         // if(lh==rh)
//         // {
//         //     return n;
//         // }
//         // n->left=build(inorder,post,lh,pivot-1,rootidx);
//         n->right=build(inorder,post,pivot+1,rh,rootidx);
//         n->left=build(inorder,post,lh,pivot-1,rootidx);

        
//         return n;
        
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int idx=inorder.size()-1;
//         return build(inorder,postorder,0,inorder.size()-1,idx);
//     }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};