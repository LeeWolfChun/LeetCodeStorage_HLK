# 🏆 [C++] LeetCode 153: Find Minimum in Rotated Sorted Array
## 💡 Tư duy thuật toán (Intuition)
Bài toán yêu cầu tìm min của 1 mảng tăng dần không tùng lăp và được xoay vòng ngẫu nhiêu 

1. **Khởi tạo:**
   * Dùng 3 con trỏ `left` = 0 , `right` = độ dài mảng -1 và  `mid`.

2. **Loop để tim ra vị trí nhỏ nhất**
   * Cập nhật mid là phần tử giửa mảng.
   * So sánh 2 phần tử left và right, nếu left < right thì mảng tăng nghiêm ngặt, lúc này trả về nums[left].
   * trường hợp còn lại thì phần tử nhỏ nhất sẽ nnằm ở khoảng giửa, lúc này so sánh phần tử mid, nếu phần tử mid nhỏ hơn left chứng tỏ trong đây chứa phần tử nhỏ nhất vì mảng đươc yêu cầu tăng dần => trong đoạn left mid chứa min nên right = mid, trường hợp còn lại chuyển left = mid.

---

## 🚀 Mã nguồn (C++)

```cpp
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
            // trường hợp duy nhất có thể trả về phần tử min ngay lập tức
                return nums[left];
            }
        }
        return min(nums[left],nums[right]);
    }
};
