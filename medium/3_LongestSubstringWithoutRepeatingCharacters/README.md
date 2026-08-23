# 🏆 [C++] LeetCode 3: Longest Substring Without Repeating Characters

## 💡 Tư duy thuật toán (Intuition)
Bài toán yêu cầu tìm chuỗi con có độ dài dài nhất không trùng lặp, giải pháp là **Sliding Window (Cửa sổ trượt)** kết hợp với mảng lưu vị trí cuối cùng xuất hiện :

1. **Khởi tạo:**
   * Dùng hai con trỏ `left` và `right` để tạo thành một "cửa sổ" `[left, right]`.
   * Dùng mảng `last_seen` (kích thước 256 để phủ toàn bộ bảng mã ASCII) nhằm lưu vị trí xuất hiện cuối cùng của mỗi ký tự với khởi tạo giá tri ban đầu là `-1`.

2. **Mở rộng cửa sổ (Dịch con trỏ `right`):**
   * Quét qua từng ký tự của chuỗi `s`.
   * Nếu ký tự hiện tại `curr_char` đã từng xuất hiện VÀ vị trí đó nằm bên trong cửa sổ trượt (`last_seen[curr_char] >= left`), ta bắt buộc phải thu hẹp cửa sổ bằng cách đẩy `left` lên ngay sau vị trí cũ đó (`last_seen[curr_char] + 1`).

3. **Cập nhật:**
   * Ghi nhận vị trí mới của `curr_char` vào mảng `last_seen`.
   * Tính toán chiều dài cửa sổ hiện tại (`right - left + 1`) và cập nhật độ dài lớn nhất `longest`.

---

## 🚀 Mã nguồn (C++)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // mảng lưu vị trí cuối cùng xuất hiện, con trỏ lèt và độ dài lớn nhất
        vector<int> last_seen(256, -1);
        int left = 0;
        int longest = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char curr_char = s[right]; // Ký tự tại con trỏ right
            
            //nếu phát hiện char[right] đã có mặt trong cửa sổ trước đó thì thu hẹp hửa sổ ra sau vị trí xuất hiện cuối cùng
            if (last_seen[curr_char] >= left) {
                left = last_seen[curr_char] + 1;
            }
            
            //câp nhật lần xuất hiện cuối cùng
            last_seen[curr_char] = right;
            
            //cập nhật chuõi dài nhất
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};
