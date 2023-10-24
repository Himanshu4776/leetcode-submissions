/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        // Approach1: use hashset or hashmap

        // HashSet<ListNode> m = new HashSet<>();
        // ListNode pointer = head;
        // while(pointer != null) {
        //     if(!m.contains(pointer)) {
        //         m.add(pointer);
        //     } else {
        //         return true;
        //     }

        //     pointer = pointer.next;
        // }
        // Approcah2: use slow and fast Pointer
        ListNode slow_pointer = head, fast_pointer = head;
        while (fast_pointer != null && fast_pointer.next != null) {
            slow_pointer = slow_pointer.next;
            fast_pointer = fast_pointer.next.next;
            if (slow_pointer == fast_pointer) {
                return true;
            }
        }

        return false;
    }
}