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
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=nullptr;
        ListNode*current=head;
        while(current!=nullptr)
        {
            ListNode*pNext=current->next;
            current->next=prev;
            prev=current;
            current=pNext;
        }
        return prev;
    }
};