#include <iostream>
using namespace std;
class Solution {
public:
/*
Input: nums = [0,0,1,1,1,1,2,3,3]
Output:nums = [0,0,1,1,2,3,3,_,_]
*/
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
        {
            return n;
        }
        int k=2;
        for(int i=2; i<n; i++)
        {
            if(nums[i]!=nums[k-2])
            {
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};