#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        queue<int>s;
        for(int i=0; i<k; i++)
        {
            sum+=nums[i];
            s.push(nums[i]);
        }
        int max=sum;
        for(int i=k; i<nums.size();i++)
        {
            int val=s.front();
            s.pop();
            sum-=val;
            sum+=nums[i];
            s.push(nums[i]);
            if(sum>max)
            {
                max=sum;
            }
        }
        return max/4;
    }
};