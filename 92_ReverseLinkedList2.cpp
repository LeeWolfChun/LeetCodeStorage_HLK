#include <iostream>
using namespoace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        int index = 0;
        while (prev !=nullptr && index < left -1) {
            prev = prev->next;
            index++;
        }
        //curr ĐANG Ở LEFT CÒN PREV ĐANG TRƯỚC LE
        ListNode * h = prev;
        prev = prev->next;
        index++;
        while(prev !=nullptr && index <=right) {
            ListNode * temp = prev ->next;
            prev->next = temp->next;
            temp->next= h->next;
            h->next = temp;
        }
        return dummy.next;
    }
};