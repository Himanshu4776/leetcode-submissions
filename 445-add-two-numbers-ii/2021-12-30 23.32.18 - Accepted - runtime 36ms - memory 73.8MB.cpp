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
        stack<int>s1,s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = NULL;
        while(!s1.empty() || !s2.empty())
        {
            if(s1.empty())
            {
                int temp = s2.top() + carry;
                ListNode* newNode = new ListNode((s2.top() + carry)%10);
                s2.pop();
                newNode->next = head;
                head = newNode;
                carry = temp/10;
            }
            else if(s2.empty())
            {
                int temp = s1.top() + carry;
                ListNode* newNode = new ListNode(temp%10);
                s1.pop();
                newNode->next = head;
                head = newNode;
                carry = temp/10;
            }
            else
            {
                int temp = s1.top() + s2.top() + carry;
                ListNode *newNode = new ListNode(temp%10);
                s1.pop();
                s2.pop();
                carry = temp/10;
                newNode->next = head;
                head = newNode;
            }
        }
        // suppose a carry is left,then
        if(carry)
        {
            ListNode *newNode = new ListNode(carry);
            carry = carry/10;
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};