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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* ans = new ListNode(0,head);
        ListNode* last = ans;
        
        while(curr != NULL)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                // Now iterate this untill you find unique value node.
                while(curr->next && curr->val == curr->next->val){
                    curr = curr->next;
                }
                last->next = curr->next;
            }
            else
            {   // No duplicate values found here.
                last = last->next;
            }
            curr = curr->next;
        }
        return ans->next;
    }
};




