#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> curr;
        for(const auto & c:s)
        {
            curr[c]++;
        }
        int i=0;
        for(const auto & c:s)
        {
            curr[c]==1;
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};