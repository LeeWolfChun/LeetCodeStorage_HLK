#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>  hashTemp(nums1.begin(),nums1.end());
        vector <int > result;

        for(const auto & val : nums2)
        {
            if(hashTemp.find(val)!=hashTemp.end())
            {
                result.push_back(val);
                hashTemp.erase(val);
            }
        }
        return result;
    }
};
