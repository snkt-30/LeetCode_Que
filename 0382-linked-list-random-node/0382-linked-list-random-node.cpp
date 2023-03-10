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
    vector<int> s;
    Solution(ListNode* head) {
        
        ListNode* temp=head;
        
        while(temp)
        {
            int x=temp->val;
            s.push_back(x);
            temp=temp->next;
        }
    }
    
    int getRandom() {
        
        int n=s.size();
        
       int RanIndex = rand() % n;
        return s[RanIndex];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */