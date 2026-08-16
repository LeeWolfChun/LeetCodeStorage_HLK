#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map <int,int> c;
        for(const auto &x:nums)
        {
            c[x]++;
            if(c[x]>=2)
            {
                return true;
            }
        }
        return false;
    }
};