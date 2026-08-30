# [C++] LeetCode 2583: Kth Largest Sum in a Binary Tree

## 📌 1. Tư duy giải quyết (Intuition)
  tính tổng value của từng level nút cây , trẩ về tổng tại vị trí k sắp xếp giảm dần.

Thay vì dử dụng trực tiếp hàm chính để đệ quy ta viết hàm phụ đảm nhận chức năng này:
1. **Chuẩn bị ở hàm chính:** tạo 1 vector chứa tổng của mỗi level với root là level 0.
2. **Hàm đệ quy:**  Hàm sẽ có 3 giá trị đầu vào gồm nút hiện tại, vector sum và level của nút hiện tại. 
4. **Hàm chính:** 
   * Khởi tạo vector sum.
   * Gọi đệ quy nút gốc sau đó sắp xếp vector sum theo thứ tự giảm dần.
   * Trả về giá trị theo thứu tự k.

---

## 🛠️ 2. Source Code (C++)

```cpp
TreeNode* LNR(TreeNode* root, long long level, vector<long long> &table) {
    if (root == nullptr) {
        return root;
    }
    if (table.size() < level + 1 ) {
        table.resize(level + 1);
    }
    table[level] += root->val;
    root->left = LNR(root->left,level+1,table);
    root->right = LNR(root->right,level+1,table);
    return root;
}
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector <long long> table;
        root = LNR(root,0,table);
        sort(table.begin(), table.end(),greater<long long>());
        if (k > table.size()) {
            return -1;
        } else {
            return table[k-1];
        }
    }
```

---

## 📊 3. Đánh giá độ phức tạp (Complexity)

* **Thời gian (Time Complexity):** $O(N)$
  * Mỗi nút được duyệt qua đúng 1 lần và cập nhật trưc tiếp lên vector, sau đấý sort 1 vector có độ dài bằng số level mà cây chứa.
  
* **Bộ nhớ (Space Complexity):** $O(N / k)$
  * Tốn bộ nhớ Call Stack cho đệ quy với độ sâu tối đa là $N / k$ tầng.
