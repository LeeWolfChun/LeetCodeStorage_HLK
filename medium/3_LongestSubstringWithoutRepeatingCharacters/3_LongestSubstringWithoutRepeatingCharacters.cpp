#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> last_seen(256,-1);
        int left = 0;
        int longest = 0;
        for (int right = 0; right < s.size(); right++) {
            char curr_char = s[right];
            if (last_seen[curr_char] >= left) {
                left = last_seen[curr_char] + 1;
            }
            last_seen[curr_char] = right;
            longest = max(longest,right - left + 1);
        }
        return longest;
    }
};