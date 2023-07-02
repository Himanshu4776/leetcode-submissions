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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        while(fast &&  fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        
        // condition if linkedlist has only 1 node or 0 nodes then
        if(!(fast && fast->next)) return NULL;
        
        while(head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};