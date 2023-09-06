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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        // Calculating the length of Linked List
        ListNode* ptr = head;
        int count=0;
        while(head!=NULL)
        {
            count++;
            head = head->next;
        }
        head = ptr;

        // The individual List Sizes to be pushed into our answer
        int list_size = count/k;

        // The Number of Extra Nodes
        int extra_nodes = count%k;
        int present_size=0;

        // Output ans
        vector<ListNode*> ans;

        // Traversing K times, as the number of Parts == K
        while(k--)
        {
            if(head!=NULL)
            {
                if(list_size)
                {
                    ListNode* newlist = new ListNode(head->val);
                    ptr = newlist;
                    present_size=1;
                    while(present_size<list_size)
                    {
                        head = head->next;
                        newlist->next = head;
                        newlist = head;
                        present_size++;
                    }
                    if(extra_nodes)
                    {
                        head = head->next;
                        newlist->next = head;
                        extra_nodes--;
                        newlist = head;
                    }
                    if(head!=NULL)
                        head = head->next;
                    if(newlist!=NULL)
                        newlist->next = NULL;
                    ans.push_back(ptr);
                }
                else if(extra_nodes)
                {
                    ListNode* newlist = new ListNode(head->val);
                    newlist->next = NULL;
                    head = head->next;
                    extra_nodes--;
                    ans.push_back(newlist);
                }
            }
            else
            {
                ListNode* newlist = NULL;
                ans.push_back(newlist);
            }
        }

        return ans;

    }
};