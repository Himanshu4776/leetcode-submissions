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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        // will throw TLE:
        // ListNode* temp = head;
        // int len= 0;
        // while(temp)
        // {
        //     len++;
        //     temp = temp->next;
        // }
        // temp = head;
        // int mid = len/2;
        // for(int i=0;i<mid-1;i++) temp = temp->next;
        // temp->next = temp->next->next;

        // using fast and slow pointer
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while(fast != NULL && fast->next != NULL)
        {
            if(slow != head) prev = prev->next;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        // now slow reached mid point and prev reached behind mid to remove it
        prev->next = slow->next;
        slow->next = NULL;
        // free(slow);
        return head;
    }
};