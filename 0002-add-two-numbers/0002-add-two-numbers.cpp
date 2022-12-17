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
        
        ListNode* ans=new ListNode(0);
        ListNode* res=ans;
        
        if(!l2)
            return l1;
        if(!l1)
            return l2;
        
        ListNode* t1=l1,*t2=l2;
        
        int carry=0;
        
        while(t1 and t2)
        {
            int a=t1->val;
            int b=t2->val;
            int sum=a+b;
            
            if(carry==1){
                sum+=1;
                --carry;
            }
            
            int rem=sum%10;
            carry=sum/10;
            
            ListNode* node=new ListNode(rem);
            ans->next=node;
            ans=ans->next;
            
            t1=t1->next;
            t2=t2->next;
        }
        
        while(t1)
        {
            int a=t1->val;
            if(carry==1)
            {
                a+=1;
                carry--;
            }
            int rem=a%10;
            carry=a/10;
            ListNode* node=new ListNode(rem);
            ans->next=node;
            ans=ans->next;
            t1=t1->next;
        }
        
           while(t2)
        {
            int a=t2->val;
            if(carry==1)
            {
                a+=1;
                carry--;
            }
            int rem=a%10;
            carry=a/10;
            ListNode* node=new ListNode(rem);
            ans->next=node;
            ans=ans->next;
            t2=t2->next;
        }
        
        if(carry==1)
        {
            ListNode* node=new ListNode(1);
            carry--;
            ans->next=node;
            ans=ans->next;
        }
        
        return res->next;
        
        
    }
};