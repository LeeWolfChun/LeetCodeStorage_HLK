# MERGE K SORTED LISTS - LeetCode #23
 
## 📌 Problem Statement
 
 Given an array of sorted linked lists, merge them all into a single linked list.
 
**Example:**
- Input: lists = [[1,4,5],[1,3,4],[2,6]]
- Output: [1,1,2,3,4,4,5,6]
**Link:** [LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/description/
 
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
[Giải thích logic đằng sau - tại sao algorithm này giải quyết bài toán]
 
---
 
## 💻 Code
 
```cpp
# Language: C+_
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
| **Time** | O(?) | [Giải thích từng vòng lặp/operation] |
| **Space** | O(?) | [Giải thích memory sử dụng] |
| **Trade-off** | [Nếu có] | [Bạn trade off gì?] |
 
---
 
## ⚠️ Edge Cases & Solutions
 
| Edge Case | How I Handle It | Code |
|-----------|-----------------|------|
| Empty input | [mô tả] | `if not input: return ...` |
| Single element | [mô tả] | `if len == 1: return ...` |
| [Your edge case] | [mô tả] | [code snippet] |
 
---
 
## 🔄 Test Cases
 
```python
# Test Case 1: Normal case
Input: [example]
Expected: [result]
Got: [result]
✅ PASS
 
# Test Case 2: Edge case
Input: [example]
Expected: [result]
Got: [result]
✅ PASS
 
# Test Case 3: Large input / Stress test
Input: [example with large data]
Expected: [result]
Got: [result]
Time: XYZ ms
✅ PASS
```
 
---
 
## 🧠 Mistakes I Made First Time
 
1. **Mistake #1: [Cái bạn sai lần đầu]**
   - What I did: [mô tả cách sai]
   - Why it was wrong: [giải thích]
   - Fix: [cách sửa]
2. **Mistake #2: [Lỗi thứ 2]**
   - What I did: [mô tả]
   - Why it was wrong: [giải thích]
   - Fix: [cách sửa]
---
 
## 💡 Lessons Learned / Optimizations
 
### **First Attempt (Brute Force)**
- Approach: [mô tả cách brute force]
- Time: O(n²) | Space: O(1)
- Problem: [vấn đề của approach này]
### **Optimized Solution**
- Approach: [cách tối ưu]
- Time: O(n) | Space: O(n)
- Improvement: [so sánh - nhanh hơn bao nhiêu?]
---
 
## 🎓 Concepts Used
 
- **Data Structure**: [Hash Map / Array / Tree / etc]
- **Algorithm Pattern**: [Two Pointers / Sliding Window / DFS / BFS / DP / etc]
- **Technique**: [Binary Search / Greedy / Divide & Conquer / etc]
---
 
## 🔗 Related Problems
 
- Problem #XXX - [Similar concept]
- Problem #YYY - [Follow-up problem]
- Problem #ZZZ - [Same data structure]
---
 
## 📚 Resources
 
- [Link to explanation article]
- [Link to similar problem solution]
- [Your learning resource]
---
 
## 🏷️ Tags
 
#tag1 #tag2 #tag3
 
*Example: #array #hashmap #two-pointers #medium*
 
---
 
## 📝 Interview Notes
 
### **If asked in interview:**
- "Walk me through your approach" → [Tóm tắt 30 giây approach]
- "Why O(n) space?" → [Giải thích cần space cho cái gì]
- "Can you optimize further?" → [Có cách nào tốt hơn không?]
- "Follow-up: What if...?" → [Xử lý variant nào?]
### **What I'd say:**
"I would approach this by [key insight], using [data structure] to [solve what]. This gives us [complexity] time and [complexity] space because [reason]."
 
---
 
## ✅ Final Checklist
 
- [ ] Code runs without errors
- [ ] All test cases pass
- [ ] Complexity analysis is correct
- [ ] Edge cases handled
- [ ] README is clear and complete
- [ ] Ready for interview questions
---
 
**Date Solved:** [Date]  
**Attempt:** 1st try / 2nd try / Multiple tries  
**Difficulty:** ⭐⭐⭐⭐⭐ (1-5 stars)  
**Confidence Level:** 40% / 70% / 90%
