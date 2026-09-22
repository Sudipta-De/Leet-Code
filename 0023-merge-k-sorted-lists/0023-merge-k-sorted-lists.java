/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            (a,b) -> a.val - b.val
        );
        for(ListNode node : lists){
            if(node!=null){
                pq.add(node);
            }
        }
        ListNode start = new ListNode(0);
        ListNode current = start;

        while ( !pq.isEmpty()){
            ListNode node = pq.poll();
            current.next = node;
            current = current.next;
            if(node.next != null){
                pq.add(node.next);
            }
        }
            return start.next;

    }

}