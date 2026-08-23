# 🚀 [25] - [Reverse Nodes in k-Group]

**Độ khó:** 🔴 Hard  
**Nền tảng:** [LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## 📝 Mô tả bài toán
*Cho 1 linked list, đảo ngược nhóm k node, nếu nhóm không đủ phần tử thì giữ nguyên*

## 💡 Ý tưởng giải quyết (Intuition & Approach)
*KHi đảo ngược thì node đầu nhóm sau khi kết thúc sẽ là node cuối nhóm, nghĩ về việc dịch từng node "sau node đầu tiên" ra sau vị trí bạn đánh dấu là "node đứng trước nhóm đó" và sau khi hoàn thành thì đệ quy phần còn lại*

1. **Phân tích ban đầu:** nhận thấy bài toán yêu cầu có thể giải quyết với tốc độ O(n) thì chỉ được duyệt qua node 1 lần,
2. **Thuật toán sử dụng:** vừa duyệt vừa đổi vị trí
3. **Các bước thực hiện:**
   - Bước 1: tạo node rỗng (dummy) nối đến head, tạo node trỏ prev vào dummy, 1 biến đếm (countGroup) để kiểm tra nhóm có đủ node không.
   - Bước 2: kiểm tra nếu không có node nào sau đó thì return luôn
   - Bước 3: tạo con trỏ curr để nắm node đầu và cũng là node cuối của danh sách sau sắp xếp
   - Bước 4: loop while lấu từng phần tử đẩy ngược lên đầu nhóm
   - Bước 5: nếu nhóm đủ thì sẽ đệ quy nhóm tiếp theo, nếu không sẽ đệ quy chạy lại từ đầu với k = countGroup mình vừa đến để trả lại vị trí nhóm như ban đầu

## ⏱️ Độ phức tạp (Complexity)
- **Độ phức tạp thời gian (Time Complexity):** $O(N)$ *(vì vòng lặp chạy qua mảng đúng 1 lần và có thêm 1 lần chạy với số lượng công đoạn < k, nên tốc độ vẫn O(N)*
- **Độ phức tạp không gian (Space Complexity):** $O(1)$ hoặc $O(N)$ *(không tao thêm khôgn gian mới )*

## 💻 Code Solution

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * prev = &dummy;
        int countGroup = 1;
        if (prev->next ==nullptr) {
            return dummy.next;
        }
        ListNode * curr = prev->next;
        while (curr->next != nullptr && countGroup < k) {
            ListNode * temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            countGroup++;
        }
        if (countGroup == k) {
            curr->next = reverseKGroup(curr->next,k);
        }
        else {
            return reverseKGroup(dummy.next,countGroup);
        }
        return dummy.next;
    }
};
