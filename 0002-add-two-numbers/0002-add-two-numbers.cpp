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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode* temp=new ListNode(-1);
        
        ListNode* res=temp;
        
        ListNode* a=l1,*b=l2;
        
        int carry=0;
        
        while(a and b)
        {
            int val1=a->val;
            int val2=b->val;
            
            int dig=(val1+val2+carry)%10;
            carry=(val1+val2+carry)/10;   
            
            temp->next=new ListNode(dig);
            temp=temp->next;
            a=a->next;
            b=b->next;
        }
        
        while(a)
        {
             int val1=a->val;
            
            int dig=(val1+carry)%10;
            carry=(val1+carry)/10;
            
            temp->next=new ListNode(dig);
            temp=temp->next;
            a=a->next;
        }
        
        while(b)
        {
            int val2=b->val;
            
            int dig=(val2+carry)%10;
            carry=(val2+carry)/10;
            
            temp->next=new ListNode(dig);
            temp=temp->next;
            b=b->next;
        }
        
        if(carry)
        {
            temp->next=new ListNode(carry);
        }
        
        return res->next;
    }
};