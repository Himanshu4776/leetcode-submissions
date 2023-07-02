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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* added = new ListNode();// new linedlist created
        ListNode *curr = added;// took new list head pointer
        int sum = 0;
        while(l1 || l2 || sum)// work if l1 is not null as well as when l2 is not null
        {
            if(l1!=NULL)
            {
                sum += l1->val;// prev carry + currnt sum of l1.
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum += l2->val;// prev carry + currnt sum of l2.
                l2 = l2->next;
            }
            curr->next = new ListNode(sum%10);// created new node with sum%10 value.
            sum = sum/10;// implemented the carry
            curr = curr->next;// shiftednew node as present 
        }
        return added->next;// new node was shifted thats why we have to return next as head.
    }
};