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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy; 
        for (int i = 0; i < n ; i++) {
            current = current->next;
        }
        ListNode* prev = &dummy;
        while (current->next != nullptr) {
            current = current->next;
            prev = prev->next;
        }
        ListNode* del = prev->next;
        prev->next = del->next;
        delete del;
        return dummy.next;
    }
};
