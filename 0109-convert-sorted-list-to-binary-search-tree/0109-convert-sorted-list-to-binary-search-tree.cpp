/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head)return nullptr;
        
        ListNode* node=head;
        
        vector<int>a;
        
        while(node)
        {
            int v=node->val;
            
            a.push_back(v);
            
            node=node->next;
        }
        
        return helper(a);
        
    }
    
    private:
    
    TreeNode* helper(vector<int>a)
    {
        if(a.size()==0)
            return nullptr;
        
        if(a.size()==1)
            return new TreeNode (a[0]);
        
        int mid=a.size()/2;
        
        TreeNode* node=new TreeNode (a[mid]);
        
        vector<int> left_a(a.begin(), a.begin()+mid);
        
        vector<int> right_a(a.begin()+mid+1, a.end());
        
        node->left=helper(left_a);
        
        node->right =helper(right_a);
        
        return node;
    }
};