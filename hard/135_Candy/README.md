# Candy - LeetCode #125
 
## 📌 Problem Statement
 
There are n childrens , each child is assigned  a rating value, each child must have at least one candy and children with higher rating get more candies than their neighbors
 
**Example:**
- Input: [1,6,10,8,7,3,2]
- Output: 18
- Constraints:
  + 1 <= n == ratings.length <= 5 * 10.
  + 0 <= ratings[i] <= 5 * 104.
**Link:** [Leetcode 135](https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150)
 
---
 
## 🎯 Approach / Solution Strategy
 
### **Key Insight**
if rating equal then candy is minimum .
### **Algorithm**
1. Step 1: Contructor  a vector save a number of candies for each child.
2. Step 2: The first loop 1 start at index 1 and finish at last index. on loop, if rating[i] > rating[i-1] then share[i] = share[i-1] + 1.
3. Step 3: The second loop is the opposite, if rating[i] > rating[i + 1] then share[i] =max(share[i +1] + 1,share[i]).
### **Why This Works**
[Giải thích logic đằng sau - tại sao algorithm này giải quyết bài toán]
 
---
 
## 💻 Code
 
```python
# Language: [Python/Java/Go/etc]
# Time: O(?)  | Space: O(?)
 
class Solution:
    def solutionName(self, ...):
        """
        Brief description of what function does
        
        Args:
            param: explanation
            
        Returns:
            explanation of return value
        """
        # Your code here
        pass
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
