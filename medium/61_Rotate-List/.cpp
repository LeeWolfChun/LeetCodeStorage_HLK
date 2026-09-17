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
        int n = 0; 
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        while (current->next != nullptr) {
            current = current->next;
            n++;
        }
        if(n <= 1 || k == 0) {
            return dummy.next;
        }
        //at this time, current = tail list
        k %= n;
        if(k == 0) {
            return dummy.next;
        }
        ListNode* previous = &dummy;
        for (int i = 0; i < n - k; i++) {
            previous = previous->next;
        }
        ListNode* temp = previous->next;
        previous->next = nullptr;
        current->next = head;
        dummy.next = temp;
        return dummy.next;
    }
};
