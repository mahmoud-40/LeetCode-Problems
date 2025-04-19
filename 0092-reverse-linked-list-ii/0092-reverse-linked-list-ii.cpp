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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        int idx = 1; 
        ListNode* start = head;
        ListNode* prev = nullptr;
        
        while (idx < left && start) {
            prev = start;
            start = start->next;
            idx++;
        }
        
        if (!start) return head; 
        
        ListNode* curr = start;
        ListNode* next = nullptr;
        ListNode* tail = start;
        
        while (idx <= right && curr) {
            next = curr->next;
            curr->next = prev ? prev->next : head;
            if (prev) {
                prev->next = curr;
            } else {
                head = curr;
            }
            tail->next = next;
            curr = next;
            idx++;
        }
        
        return head;
    }
};