
# Jump game - LeetCode #55
 
## 📌 Problem Statement
 
Dive an array containing intergers, start at index 0, current number is maximum jumping. return true if finish at last index.
 
**Example:**
- Input: [2,3,1,1,2]
- Output: true
- Constraints: 
**Link:** [Leetcode 55](https://leetcode.com/problems/jump-game/description/)
 
---
 
## 🎯 Approach / Solution Strategy
 
### **Key Insight**
Usable DP(dynamic programming) but i following a greedy, just interare through the array one. Think about the current index and then jump the farthest, update the farthest. if browse at index > farthest , break loop because we couldn't come it and return false. else we can come it so return true.
 
### **Algorithm**
1. Step 1: operator integer n = size of nums, integer farthest = nums[0] and return true if n <= 1.
2. Step 2: loop with i = 0 , i <=farthest and i < n, i++.
3. Step 3: om loop .update farthest with max between farthest and current index plus jump there.
4. Step 4: if farthest >= n-1 ,return true and else return false.
### **Why This Works**
the above agorithrm use one loop begin at index = 0 and finish at last index of nums , so time comflexity to be o(n) and space comflexity to be o(1).
 
---
 
## 💻 Code
 
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        if( n <= 1 ) return true;
        int farthest = nums[0];
        for( int i = 0; i <= farthest && i < n; i ++){
            farthest = max(farthest,i + nums[i]);
        }
        return (farthest >= n - 1) ? true : false;
    }
};
```
 
---
 
## 📊 Complexity Analysis
 
| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(n) | the above agorithrm use one loop begin at index = 0 and finish at last index of nums |
| **Space** | O(1) | no use extra array |

 
---
 
## ⚠️ Edge Cases & Solutions
 
| Edge Case | How I Handle It | Code |
|-----------|-----------------|------|
| Empty input | [] | `if (n <= 1) return true;` |
| Single element | [0] | `if (n <= 1) return true;` |
 
---
 
## 🔄 Test Cases
 
```cpp
# Test Case 1: Normal case
Input: [2,3,1,1,4]
Expected: true
Got: true
✅ PASS
 
# Test Case 2: false case
Input: [3,2,1,0,4]
Expected: false
Got: false
✅ PASS
 
# Test Case 3: empty case
Input:[]
Expected: true
Got: true
✅ PASS
```
 
---
 
## 🎓 Concepts Used
 
- **Data Structure**: array
- **Algorithm Pattern**: Dynamic Programing
- **Technique**: greedt
---

## 🏷️ Tags
 
#array #Dynamic programing #greedy
 
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
**Attempt:** 10 tries 
**Difficulty:** ⭐⭐⭐ 
**Confidence Level:** 90%
