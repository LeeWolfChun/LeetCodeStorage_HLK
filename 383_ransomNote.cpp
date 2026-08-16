class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char,int> table;
        for (auto  c: magazine) table[c]++;
        for (auto a : ransomNote) {
            table[a]--;
            if(table[a]< 0) return false;
        }
        return true;
    }
};