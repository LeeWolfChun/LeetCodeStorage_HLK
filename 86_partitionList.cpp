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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * curr = &dummy;
        ListNode * prev = nullptr;
        while (curr->next != nullptr) {
            //GẶP NÚT NHỎ HƠN NHƯNG CHƯA XÁT ĐỊNH NÚT LỚN HƠN THÌ BỎ QUA
            if (prev == nullptr && curr->next->val >= x) {
            prev = curr;
            }
            /*GẶP NÚT NHỎ HƠN X VÀ ĐÃ CÓ PREVRIOUS THÌ SẼ ĐẨY NÚ NÓ RA SAU PREVIOUS
            VÀ CẬP NHẬT LẠI PREVIOUS*/
            if (prev != nullptr && curr->next->val < x) {
                ListNode * temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                prev = prev->next;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};