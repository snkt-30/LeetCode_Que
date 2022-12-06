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
    ListNode* oddEvenList(ListNode* head) {
     if(head==NULL)
     {
         return NULL;
     }
     if(head->next==NULL or head->next->next==NULL)
    {
            return head;
     }
        
        ListNode* end=head;
        int count=0;
        while(end->next)
        {
            end=end->next;
            count+=1;
        }
        
        ListNode* temp=head;
        count=(count%2==0)?(count/2):(count/2)+1;
        
        while(count)
        {
            end->next=temp->next;
            temp->next=temp->next->next;
            end->next->next=NULL;
            
            temp=temp->next;
            end=end->next;
            count--;
        }
        return head;
       
    }
};