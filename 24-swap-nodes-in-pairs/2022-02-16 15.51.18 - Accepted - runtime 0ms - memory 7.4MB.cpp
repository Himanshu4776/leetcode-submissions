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
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* current = temp;
        // as we require an extra node on behind to swap or ahead to swap
        while(current->next && current->next->next)
        {
            ListNode* first = current->next;
            // the first node to swap
            ListNode* second = current->next->next;
            // the second node to swap
            first->next = second->next;
            second->next = first;
            current->next = second;// placed current pointer to again the swapped point.
            current = current->next->next;// lets iterate ahead now.
        }
        return temp->next;
    }
};