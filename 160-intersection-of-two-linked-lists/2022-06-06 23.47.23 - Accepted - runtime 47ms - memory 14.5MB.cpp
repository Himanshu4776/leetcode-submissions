/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
			if(ptr1 == NULL){// A linkedlist ended so its pointer is now
                // linked with B linked list
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;// if not null then just traverse.
			}
			if(ptr2 == NULL){// B linkedlist ended so its pointer is now
                // linked with A linked list
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next; // if not null then just traverse.
			}
		}
		return ptr1;
    }
};