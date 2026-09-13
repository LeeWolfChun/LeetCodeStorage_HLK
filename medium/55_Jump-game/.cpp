class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        if( n <= 1 ) return true;
        int farthest = nums[0];
        for( int i = 0; i <= farthest && i < n; i ++){
            farthest = max(farthest,i + nums[i]);
        }
        return (farthest >= n - 1) ? true : false;
    }
};
