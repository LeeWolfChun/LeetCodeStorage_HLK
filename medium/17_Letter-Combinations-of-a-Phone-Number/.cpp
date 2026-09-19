class Solution {
public:
    vector <string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void scramble(vector <string>& result, string digits, int index, string path) {
        int number = digits[index] - '0';
        if (path.length() == digits.length()) {
            result.push_back(path);
        } else {
            for (auto c : letters[number]) {
                scramble(result, digits, index + 1, path + c);
            }
        }
    }
    vector<string> letterCombinations(string digits) {   
        vector <string> result;
        scramble(result, digits, 0, "");
        return result;
    }
};
