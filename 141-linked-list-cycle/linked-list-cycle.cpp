/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;

        while(slow && fast && fast->next) {
            if(slow == fast) {
                if(count) return true;
                else count++;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};