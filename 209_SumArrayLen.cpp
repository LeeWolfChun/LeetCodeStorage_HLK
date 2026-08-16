#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0;
        int right=0;
        int n=nums.size();
        int minSum=INT_MAX;

        while(right<n)
        {
            sum+=nums[right];
            while(sum>=target)
            {
                minSum=min(right-left+1,minSum);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        return ( minSum == INT_MAX ) ? 0 : minSum;
    }
    
};