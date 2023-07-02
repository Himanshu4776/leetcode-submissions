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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
        {
            return head;
        }
        while(head!=NULL && head->val==val)
        {
            head = head->next;
        }
        ListNode*curr = head,*prev = NULL;
        if(head != NULL && head->val == val)
        {
            return head->next;
        }
        while(curr)// if not head and not tail having value val.
        {
            if(curr->val == val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};