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
TreeNode* LNR(TreeNode* root, int level, vector<int> &table) {
    if (root == nullptr) {
        return root;
    }
    if (table.size() < level + 1 ) {
        table.resize(level + 1);
    }
    table[level] += root.val;
    root->left = LNR(root->left,level+1,table);
    root->right = LNR(root->right,level+1,table);
    return root;
}
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector <int> table;
        root = LNR(root,0,table);
        sort.(table.begin(), table.end());
        return table[k-1];
    }
};