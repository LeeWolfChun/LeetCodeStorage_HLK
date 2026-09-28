# MERGE K SORTED LISTS - LeetCode #23
 
## 📌 Problem Statement
 
 Given an array of sorted linked lists, merge them all into a single linked list.
 
**Example:**
- Input: lists = [[1,4,5],[1,3,4],[2,6]]
- Output: [1,1,2,3,4,4,5,6]
**Link:** [LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/description/)
 
---
 
## 🎯 Approach / Solution Strategy
 
### **Key Insight**
Priority queue can be used to take out a linked list from queue with smallest head value of the array
 
### **Algorithm**
1. Step 1: Define a comparison method can be used in priority queue.
2. Step 2: in main func, declaration a node point to result linked list, a priority_queue with compare defined
3. Step 3: iterate through list and add this to pq.
4. Step 4: tale out the  head node from pq, add this to merge list, head is point to next node, add new list edited to pq. 
### **Why This Works**
added all the head node of list to priority queue with compare defined. take out first node from the queue, this is a smallest numberof the list. Added it to result list and the priority queue again with next node 
 
---
 
## 💻 Code
 
```cpp
# Language: C++
# Time: O(N log k)  | Space: O(N)
 
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
```
---
 
## 📊 Complexity Analysis
 
| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(N log K) | iterate each node once and add to the queue with complexity is log k |
| **Space** | O(N) | not use extra space |
 
---
 
## ⚠️ Edge Cases & Solutions
 
| Edge Case | How I Handle It | Code |
|-----------|-----------------|------|
| Empty input | [[]] | return dummy.next is nullprt |
 
---
 
## 🔄 Test Cases
 
```cpp
# Test Case 1: Normal case
Input: [[1,4,5],[1,3,4],[2,6]]
Expected: [1,1,2,3,4,4,5,6]
✅ PASS
 
# Test Case 2: Edge case
Input: [[]]
Expected: []
✅ PASS
 
```
---
 
## 🧠 Mistakes I Made First Time
 
1. **Mistake #1: compare each node**
   - What I did: compare each node and select smallest
   - Why it was wrong: that's not wrong, but the time cpomplexity is major issue.
   - Fix: use priority queue
   - 
---
