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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)return nullptr;
        if(!head->next)return head;
        
        int len=1;

        
        ListNode* temp=head;
        
        while(temp->next)
        {
            temp=temp->next;
            len++;
        }
        
        k=k%len;   // make sure the rotation within the frame
        
        if(k==0)return head;
        ListNode* node=head,*newH;
        
        for(int i=1;i<len-k;i++)
        {
            node=node->next;
        }
        
        newH=node->next;
        node->next=nullptr;
        temp->next=head;
        
        return newH;
    }
};