#include <iostream>
using namespace std;
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