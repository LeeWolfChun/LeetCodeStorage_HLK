#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
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