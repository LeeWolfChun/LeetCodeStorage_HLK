struct compare {
    bool operator()(ListNode* a , ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int n = lists.size();
        if( n == 0 ) {
            return dummy.next;
        } else if (n == 1) {
            return lists[0];
        }
        priority_queue <ListNode*, vector <ListNode*> , compare>  pq;
        for (ListNode* node : lists) {
            if (node != nullptr) 
            pq.push(node); 
        }
        while(!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if(temp == nullptr) {
                break;
            } else {
                current->next = temp;
                current = current->next;
                temp = temp->next;
                if (temp != nullptr ) {
                    pq.push(temp);
                }
            }
        }
        return dummy.next;
    }
};
