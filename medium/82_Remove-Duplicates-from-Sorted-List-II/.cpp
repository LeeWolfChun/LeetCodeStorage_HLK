class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        if(curr == nullptr || curr->next == nullptr) {
            return dummy.next;
        }
        int valdelete;
        while (curr != nullptr) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                valdelete = curr->val;
                while (curr != nullptr && curr->val == valdelete) {
                    ListNode* del = curr;
                    curr = curr->next;
                    delete del;
                }
                prev->next = curr;
            } else {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};
