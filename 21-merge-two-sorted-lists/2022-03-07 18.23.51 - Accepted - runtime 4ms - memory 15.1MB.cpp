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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* l3 = new ListNode();
        ListNode* ptr = l3;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                ptr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else
            {
                ptr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            ptr = ptr->next;
        }
        if(l1)
        {
            while(l1)
            {
                ptr->next = new ListNode(l1->val);
                l1 = l1->next;
                ptr = ptr->next;
            }
        }
        if(l2)
        {
            while(l2)
            {
                ptr->next = new ListNode(l2->val);
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        
        return l3->next;
    }
};