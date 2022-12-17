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
        
        vector<int> s;
        
        if(!head)return nullptr;
        
        if(!head->next)return head;
        
        ListNode* temp=head;
        
        
        while(temp)
        {
            int x=temp->val;
            s.push_back(x);
            temp=temp->next;
        }
        int n=s.size();
        
        k=k%n;
        rotate(s.begin(),s.begin()+(n-k),s.end());
        
        ListNode* ans=new ListNode(0);
        ListNode* res=ans;
        
        for(int i=0;i<s.size();i++)
        {
            ListNode* node=new ListNode(s[i]);
            ans->next=node;
            ans=ans->next;
        }
        return res->next;
    }
};