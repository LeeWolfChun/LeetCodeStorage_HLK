#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        double maxVolume=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            double volumeResults=
            min(height[left],height[right])*(right-left);
            if(volumeResults>maxVolume)
            {
                maxVolume=volumeResults;
            }
            if(height[left]>height[right])right--;
            else left++;
        }
        return maxVolume;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int head = 0;
        int tail = height.size() - 1;
        int maxArea = 0;
        while (head < tail) {
            int currArea = min(height[head],height[tail]) * (tail - head);
            maxArea = max(currArea,maxArea);
            height[head] < height[tail] ? head++ : tail--;
        }
        return maxArea;
    }
};