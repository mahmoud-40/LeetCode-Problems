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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Calculate the length of the list and find the tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Compute effective number of rotations
        k = k % n;
        if (k == 0) return head;
        
        // Use slow and fast pointers to find the new head and tail
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move fast pointer k nodes ahead
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        // Move both pointers until fast reaches the tail
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Perform rotation
        ListNode* new_head = slow->next;
        slow->next = nullptr;
        tail->next = head;
        
        return new_head;
    }
};