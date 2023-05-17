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
    
    private:
    
    int len(ListNode* node)
    {
        if(!node)
            return 0;
        
        ListNode* temp=node;
        
        int cnt=0;
        
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        
        return cnt;
    }
public:
    int pairSum(ListNode* head) {
        
        
        
        if(!head)
            return 0;
        stack<int> st;
        
        int n=len(head);
        
        int ans=0;
        
        int i=0;
        
        ListNode* temp=head;
        
        while(i<n)
        {
            if(i<(n/2))
            {
                st.push(temp->val);
            }
            else
            {
                int v=st.top()+temp->val;
                
                ans=max(ans,v);
                st.pop();
            }
            temp=temp->next;
            i++;
        }
        
        return ans;
        
    }
};