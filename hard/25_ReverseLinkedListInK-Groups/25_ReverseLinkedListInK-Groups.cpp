#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * prev = &dummy;
        int countGroup = 1;
        if (prev->next ==nullptr) {
            return dummy.next;
        }
        ListNode * curr = prev->next;
        while (curr->next != nullptr && countGroup < k) {
            ListNode * temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            countGroup++;
        }
        if (countGroup == k) {
            curr->next = reverseKGroup(curr->next,k);
        }
        else {
            return reverseKGroup(dummy.next,countGroup);
        }
        return dummy.next;
    }
};
