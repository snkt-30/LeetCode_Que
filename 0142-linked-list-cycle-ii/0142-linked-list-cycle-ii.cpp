/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
  
        if(!head or !head->next)
        {
            return nullptr;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
              if(fast==slow)
                 break;
            
        }
        
         if(!fast->next || !fast->next->next)
        {
            return nullptr;
        }
        
        ListNode* check=head;
        
        while( check!=slow)
        {
            slow=slow->next;
            check=check->next;
        }
        
        return slow;
    }
};