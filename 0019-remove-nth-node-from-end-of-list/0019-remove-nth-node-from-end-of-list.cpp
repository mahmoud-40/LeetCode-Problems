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
        
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        
        ListNode* prev = dummy;
        for (int i = 0; i < size - n; i++) {
            prev = prev->next;
        }
        
        ListNode* toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;  
        
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};