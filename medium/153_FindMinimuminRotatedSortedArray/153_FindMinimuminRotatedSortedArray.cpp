#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left < right - 1) {
            mid = left + (right - left)/2;
            if (nums[left] > nums[right]) {
                if (nums[mid] > nums[left]) {
                    left = mid;
                } else {
                    right = mid;
                }
            } else {
                return nums[left];
            }
        }
        return min(nums[left],nums[right]);
    }
};