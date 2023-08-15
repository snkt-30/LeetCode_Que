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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        
        if(!head)
            return nullptr;
        
        
        
        ListNode* temp= new ListNode(-1);
        ListNode* sec= new ListNode(-1);
        
        ListNode*  res=temp;
        ListNode* tr=sec;
        
        ListNode* node=head;
        
        while(node)
        {
            int val=node->val;
            
            if(val<x)
            {
                sec->next=new ListNode(val);
                sec=sec->next;
            }
            else
            {
                temp->next=new ListNode(val);
                temp=temp->next;
            }
            
            node=node->next;
        }
        
        sec->next=res->next;
        
        
        
        return tr->next;
    }
};