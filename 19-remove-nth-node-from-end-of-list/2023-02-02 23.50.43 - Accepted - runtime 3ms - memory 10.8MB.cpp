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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL)
        {
            length += 1;
            temp = temp->next;
        }
        // if head needs to be removed
        if(length == n)return head->next;
        // now remove that nth node from linkedlist
        temp = head;
        for(int i=1;i<length-n;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};