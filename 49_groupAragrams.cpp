#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> groups;
        for (const auto & str : strs) {
            string key = str;
            sort(key.begin() , key.end());
            groups[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto [key,arr] : groups) {
            res.push_back(arr);
        }
        return res;
    }
};