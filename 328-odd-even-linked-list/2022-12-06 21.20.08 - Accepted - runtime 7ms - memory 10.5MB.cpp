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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* last = head;
        int length = 0;
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        if(head->next->next == NULL) return head;
        // Moved it to last point so linkedlist can be modified
        while(last->next != NULL) {
            last = last->next;
            length++;
        }
        // Take 2 pointers so that we can complete the swaps at end of LL
        ListNode* first = head->next;
        ListNode* second = head;
        
        bool check = 1;
        for(int i=0;i<length;i++) {
            if(check) {
                // make swaps
                second->next = first->next;
                first->next = NULL;
                last->next = first;
                last = first;
                first = second->next;
                check = 0;
            }
            else {
                check = 1;
                second = second->next;
                first = first->next;
            }
        }

        return head;
    }
};