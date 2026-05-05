1class Solution {
2    public ListNode rotateRight(ListNode head, int k) {
3        if (head == null || head.next == null || k == 0) return head;
4
5        ListNode tail = head;
6        int n = 1;
7
8        while (tail.next != null) {
9            n++;
10            tail = tail.next;
11        }
12
13        k = k % n;
14        if (k == 0) return head;
15
16        ListNode slow = head;
17        ListNode fast = head;
18
19        while (k-- > 0) {
20            fast = fast.next;
21        }
22
23        while (fast.next != null) {
24            fast = fast.next;
25            slow = slow.next;
26        }
27
28        ListNode new_head = slow.next;
29        slow.next = null; 
30        tail.next = head; 
31        
32        return new_head;
33    }
34}