# 🌲 [C++] LeetCode 98: Validate Binary Search Tree

## 💡 Ý tưởng & Tư duy (Intuition & Approach)
* Để kiểm tra các nút của cây thì ta sẽ so sánh nút trái sẽ phải nhỏ hơn cha còn nút phải lớn hơn nút cha>
* Nếu chỉ so sánh đơn giản như thế thì trong đa só trường hợp sẽ hợp lệ. Nếu nút con bên trái của nút bên phải mà nhỏ hơn nút gốc sẽ có vấn đề.
* để giải quyết nó thì ta sẽ thêm vào 2 biến để ghi lại khoảng giá trị mà nút dang xét hợp lệ. Nếu đệ quy về nút trái thì phải điều chỉnh biên phải về giá trị của nút cha, nếu đệ quy về bên trái thì phải điều chnhr biên trái thành nút cha

## ⚠️ Các trường hợp đặc biệt (Edge Cases)
* **Lỗi giá trị biên:** Nếu gặp trường hợp số quá lớn hoặc quá bé thì thuật toán sẽ lỗi, nên set ban đầu biên trái là LONG_MIN và biên phải là LONG_MAX.
* **Lỗi ghi đè bool:** Nếu cập nhật bool lần lượt từ trái qua phải thì nếu false sẽ bị true ghi đè nếu có sai. Dể giải quyết nó thì chúng ta sẽ sử dụng toán tử && để so sánh đệ quy trái và phải cùng lúc.
## 🛠️ Mã nguồn (Source Code)

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
bool checkNode(TreeNode* root, long long left, long long right) {
    if (root == nullptr) {
        return true;
    }
    if(root->val <= left || root->val >=right) {
        return false;
    }
    return checkNode(root->left,left,root->node) && checkNode(root->right,root->val,right);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return checkNode(root,INT_MIN,INT_MAX);
    }
};
