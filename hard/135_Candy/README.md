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
 
```cpp
# Language: [C++]
# Time: O(N)  | Space: O(N)
 
class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        if (n ==1 ) return 1;
        int total = 0;
        vector <int> crit(n,1);
        if (rating[0] > rating[1]) crit[0] = 2;
        for ( int i = 1; i < n; i ++) {
            if (rating[i] > rating[i-1]) {
                crit[i] = crit[i-1] + 1;
            }
        }
        total += crit[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if(rating[i] > rating[i + 1]) {
                crit[i] =max(crit[i +1] + 1,crit[i]);
            }
            total += crit[i];
        }
        return total;
    }
};
```
 
---
 
## 📊 Complexity Analysis
 
| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(N) | 1 forward loop anđ 1 reverse loop |
| **Space** | O(N) | 1 vector crit |
 
 
---
 
## 🔄 Test Cases
 
```cpp
# Test Case 1: Normal case
Input: [1,2,2]
Expected: 4
Got: 4
✅ PASS
 
# Test Case 2: Edge case
Input: [1,0,2]
Expected: 5
Got: 5
✅ PASS

```
 
---
 
## 🧠 Mistakes I Made First Time
 
1. **Mistake #1: Once forward loop**
   - What I did: run exacly 1 loop.
   - Why it was wrong: only comparing rating current with neighbor on the left.
   - Fix: coding plus one loop reverse helped commparing with neighbor on the right.

---
 
## 🏷️ Tags
 
#array #greedy #hard
 
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
 
- [x] Code runs without errors
- [x] All test cases pass
- [x] Complexity analysis is correct
- [x] Edge cases handled
- [x] README is clear and complete
- [x] Ready for interview questions
---
 
**Date Solved:** [Date]  
**Attempt:** 1st try / 2nd try / Multiple tries  
**Difficulty:** ⭐⭐⭐⭐⭐ (1-5 stars)  
**Confidence Level:** 40% / 70% / 90%
