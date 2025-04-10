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
    ListNode* reverse(ListNode* current, ListNode* newHead){
        if(!current){
            return newHead;
        }

        ListNode* nextNode = current->next;

        current->next = newHead;
        newHead = current;

        return reverse(nextNode, newHead);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        return reverse(head, ans);
    }
};