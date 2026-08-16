struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy= ListNode(0);
        dummy.next=head;
        ListNode * key=head;
        ListNode *curr;
        while(curr!=dummy.next)
        {
            curr=head;
            if(curr->val>curr->next->val)
            {
                swap(curr->val,curr->next->val);
            }
            else
            {
                dummy=
            }
        }
    }
};