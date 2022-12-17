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
    ListNode* swapPairs(ListNode* head) {
        
        vector<int> s;
        
        ListNode* curr=head;
        
        while(curr)
        {
            int x=curr->val;
            s.push_back(x);
            curr=curr->next;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0 and i<s.size()-1)
            {
                swap(s[i],s[i+1]);
            }
        }
        
        ListNode* ans=new ListNode(0);
        ListNode* res=ans;
        for(int i=0;i<s.size();i++)
        {
            int val=s[i];
            ListNode* node=new ListNode(val);
            ans->next=node;
            ans=ans->next;
        }
        return res->next;
    }
};