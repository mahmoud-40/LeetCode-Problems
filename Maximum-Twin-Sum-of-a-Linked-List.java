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
23        
24        while (curr != null) {
25            ListNode temp = curr.next; 
26            curr.next = prev;           
27            prev = curr;                 
28            curr = temp;       
29        }
30        
31        int mx_sum = 0;
32        ListNode first = head;
33        ListNode sec = prev;
34        
35        while (sec != null) {
36            mx_sum = Math.max(mx_sum, first.val + sec.val);
37            first = first.next;
38            sec = sec.next;
39        }
40        
41        return mx_sum;
42    }
43}