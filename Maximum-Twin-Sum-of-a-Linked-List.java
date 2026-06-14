1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 * int val;
5 * ListNode next;
6 * ListNode() {}
7 * ListNode(int val) { this.val = val; }
8 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11class Solution {
12    public int pairSum(ListNode head) {
13        ListNode slow = head;
14        ListNode fast = head;
15        
16        while (fast != null && fast.next != null) {
17            slow = slow.next;
18            fast = fast.next.next;
19        }
20        
21        ListNode prev = null;
22        ListNode curr = slow; 
23        ListNode temp; 
24        
25        while (curr != null) {
26            temp = curr.next; 
27            curr.next = prev;           
28            prev = curr;                 
29            curr = temp;       
30        }
31        
32        int mx_sum = 0;
33        ListNode first = head;
34        ListNode sec = prev;
35        
36        while (sec != null) {
37            mx_sum = Math.max(mx_sum, first.val + sec.val);
38            first = first.next;
39            sec = sec.next;
40        }
41        
42        return mx_sum;
43    }
44}