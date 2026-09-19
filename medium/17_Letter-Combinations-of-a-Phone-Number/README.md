# Letter Combinations of a Phone Number - LeetCode #17
 
## 📌 Problem Statement
 Given a string containg digits from 2-9 inclusive, return all possible letter conbinations that the numbers could represent
 
**Example:**
- Input: "23"
- Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
- Constraints: 
**Link:** [leetcode 17](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150)
 
---
 
## 🎯 Approach / Solution Strategy
 
### **Key Insight**
Usable backchecking if digits = 1 return 3 to 4  of scrambles, if digits > 1, use first char of number 1 and pick from 1 to 3 or 4 of letter second. similary, it will have more combinations than larger candle digits.
 
### **Algorithm**
1. Step 1: in class Solution: reclare a map of letters;
2. Step 2: Create a recursive function add a combination if its size is equal to the size of digits. else it will recursively to the next number and add more letter.
3. 3. Step 3: in main func,  reclare an empty vector of type string result, calling recursive function and return result.
### **Why This Works**
example: digits = "23" , first call with path = "", because the size of the path is smaller than the size of the digits, so it recursively the next number, i.e index + 1 and path + first character has been added.
---
 
## 💻 Code
 
```cpp
# Language: C++
# Time: O(N ^ N)  | Space: O(N ^ N)
 
class Solution {
public:
    vector <string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void scramble(vector <string> &result,string digits, int index,string path) {
        int number = (int)digits[index] - '0';
        if (path.length() == digits.length()) {
            result.push_back(path);
        } else {
            for ( auto c :letters[number]) {
                scramble(result,digits,index + 1, path + c);
            }
        }
    }
    vector<string> letterCombinations(string digits) {   
        vector <string> result;
        scramble(result, digits, 0, "");
        return result;
    }
};
```
 
---
 
## 📊 Complexity Analysis
 
| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| **Time** | O(N ^ N) | because if n = 2 so that it will have 4 conbinations of letters |
| **Space** | O(N ^ N) | the generated space is derecly propotional  to the time complexity |

---
 
## 🔄 Test Cases
 
```cpp
# Test Case 1: Normal case
Input: "2"
Output: ["a","b","c"]
✅ PASS
 
# Test Case 2: Normal case
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
✅ PASS
```
---
 

