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
   int res = 0;
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0, 0};
        pair<int, int> ltSub = solve(root->left);
        pair<int, int> rtSub = solve(root->right);
        int sum = ltSub.first + rtSub.first + root->val;
        int ct = ltSub.second + rtSub.second + 1;
        if(floor(sum/ct)==root->val)  res++;
        return {sum, ct};       
       }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};