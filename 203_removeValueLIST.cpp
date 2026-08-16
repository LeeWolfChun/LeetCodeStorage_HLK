#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void DelNode(ListNode * prev)
{
    ListNode*del=prev->next;
    prev->next=del->next;
    delete del;
}
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        while(head!=nullptr&&head->val==val)
        {
            ListNode*del=head;
            if(del->next==nullptr)
            {
                head=nullptr;
            }
            else
            {
                head=del->next;
            }
            delete del;
        }
        if(head==nullptr) return head;
        ListNode*current=head;
        while(current->next!=nullptr)
        {
            if(current->next->val==val)
            {
                if(current->next->next==nullptr)
                {
                    ListNode*del=current->next;
                    current->next=nullptr;
                    delete del;
                }
                else
                {
                    DelNode(current);
                }
            }  
            else
            {
                current=current->next;
            }
        }
        return head;
    }
};