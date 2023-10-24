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
        HashSet<ListNode> m = new HashSet<>();
        if(head == null) return false;

        ListNode pointer = head;
        while(pointer != null) {
            if(!m.contains(pointer)) {
                m.add(pointer);
            } else {
                return true;
            }

            pointer = pointer.next;
        }

        return false;
    }
}