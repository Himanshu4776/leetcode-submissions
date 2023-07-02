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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head,*prev = NULL, *temp = NULL;
        while(fast != NULL && slow != NULL && fast->next)
        {
            fast = fast->next->next;
            // reverse part
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // If ll if of odd length then fast will stop just before NULL
        // so in that case we have to move the slow pointer above mid node.
        if(fast != NULL) slow = slow->next;
        
        while(prev && slow) {
            if(prev->val != slow->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};