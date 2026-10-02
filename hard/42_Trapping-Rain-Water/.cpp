class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0,
        right = n - 1,
        maxleft = height[left],
        maxright = height[right],
        result = 0;
        while(left < right) {
            if (maxleft < maxright) {
                left++;
                int water = min(maxleft,maxright) - height[left];
                if (water <=0) {
                    maxleft = max(maxleft, height[left]);
                } else {
                    result += water;
                }
            } else {
                right--;
                int water = min(maxleft,maxright) - height[right];
                if (water <=0) {
                    maxright = max(maxright, height[right]);
                } else {
                    result += water;
                }
            }
        }
        return result;
    }
};
