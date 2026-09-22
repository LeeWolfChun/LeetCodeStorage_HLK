# 82. Remove Duplicates from Sorted List II - LeetCode #82
 
## 📌 Problem Statement
 
Give a sorted Linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
**Example:**
- Input: head = [1,2,3,3,4,4,5]
- Output: [1,2,5]
**Link:** [LeetCode 82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)
 
---
 
## 🎯 Approach / Solution Strategy
 
### **Key Insight**
I use this which will we time complexity equal O(n) 
 
### **Algorithm**
1. Step 1: constructor a empty node have point next to head, prev point to dummy and curr point to head and integer name is duplicate.
3. Step 2: Core element of algorithrm, while loop stop if curr = nullptr. if the value of prev and the value curr are equal, then duplicate assigned equal value. Also within that unfinished if block, we use a while loop, that delete all nodes that are equal.
4. Step 3: in else block, prev next and curr also next. finished while loop, return dummy.next.
### **Why This Works**
this algorithrm solve problem because it browses list, tick at the duplicate numbers and delete all duplicate numbers.
---
 
## 💻 Code
 
```cpp
# Language: C++
# Time: O(n)  | Space: O(n)
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        if(curr == nullptr || curr->next == nullptr) {
            return dummy.next;
        }
        ListNode* prev = &dummy;
        ListNode* curr = head;
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
```
 
---
 
## 📊 Complexity Analysis
 
| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(N) | interate through each node exactly once |
| **Space** | O(?) | do not use additional memory  |
---
