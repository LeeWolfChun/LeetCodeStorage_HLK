#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> hashtable;
        for(const auto &c:s)
        {
            hashtable[c]++;
        }
        for(const auto &c:t)
        {
            if(s.length() != t.length()) return false;
            hashtable[c]--;
        }
        for(const auto [c,res]:hashtable)
        {
            if(res!=0)
            {
                return false;
            }
        }
        return true;
    }
};