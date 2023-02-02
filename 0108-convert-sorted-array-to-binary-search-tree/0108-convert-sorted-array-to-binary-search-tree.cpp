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
TreeNode *sortedArrayToBST(vector<int> &nums) {
    
    if(nums.size()==0)return nullptr;
    
    
    if(nums.size()==1)
    {
        return new TreeNode(nums[0]);
    }
    
    return helper(nums);
    }
    private:
    TreeNode* helper(vector<int>&a)
    {
        if(a.size()==0)return nullptr;
        
        if(a.size()==1)
            return new TreeNode (a[0]);
        
        int mid=a.size()/2;
        
        TreeNode* node= new TreeNode(a[mid]);
        
        vector<int> left_a(a.begin(),a.begin()+mid);
        vector<int> right_a(a.begin()+mid+1,a.end());
        
        node->left=helper(left_a);
        node->right=helper(right_a);
        
        return node;
    }
};