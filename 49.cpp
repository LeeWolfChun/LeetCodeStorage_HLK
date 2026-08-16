#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> dem;
        for(const auto& fair:strs)
        {
            string key= fair;
            sort(key.begin(), key.end());
            dem[key].push_back(fair);
        }
        vector<vector<string>> result;
        for(const auto& fair:dem)
        {
            result.push_back(fair.second);
        }
        return result;

        
    }
};