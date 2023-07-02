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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head, *temp = NULL, *prev = NULL;
        while(fast && slow && fast->next)
        {
            fast = fast->next->next;
            // reverse case
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        int sol = INT_MIN;
        while(prev && slow)
        {
            sol = max(sol,prev->val+slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return sol;
    }
};