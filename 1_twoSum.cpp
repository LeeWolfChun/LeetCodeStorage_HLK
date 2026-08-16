#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> hashmap;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int compensation = target-nums[i];
            if(hashmap.find(compensation)!=hashmap.end())
            {
                return {i,hashmap[compensation]};
            }
            hashmap[nums[i]]=i;
        }   
        return{};
    }
};  