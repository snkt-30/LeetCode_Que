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
    int len(ListNode* head)
    {
        int cnt=0;
        ListNode* temp=head;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int l=len(head);
        
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL and n==1)
        {
            return nullptr;
        }
        ListNode* temp=head;
      
        
        if(l==n)
        {
            return head->next;
        } 
        
        l=l-n-1;
        
        while(temp and l>=1)
        {
            temp=temp->next;
            l--;
        }
        
        ListNode* del=temp->next;
        temp->next=temp->next->next;
        
        delete(del);
        
        return head;
    }
};