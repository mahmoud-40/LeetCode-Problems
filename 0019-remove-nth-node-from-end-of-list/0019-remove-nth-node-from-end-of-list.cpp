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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i = 0; i <= n; i++){ // fast moves n + 1 steps forward
            fast = fast->next;
        }

        while(fast){ // then both slow and fast moves together.
            slow = slow->next;
            fast = fast->next;
        } // when fast reaches the last node, the slow is on the (n - 1) node

        slow->next = slow->next->next; // so now we connect (n - 1) -> (n + 1)

        return dummy->next;
    }
};