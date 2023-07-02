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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>m;
        ListNode*curr=head,*prev = NULL;
        while(curr != NULL && curr->next != NULL)
        {
            ListNode *nextNode = curr->next;
            if(curr->val == nextNode->val)
            {
                curr->next = nextNode->next;
            }
            else
            {
                curr = nextNode;
                nextNode = nextNode->next;
            }
        }
        return head;
    }
};