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
class Solution {
public:
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)
        {
            return true;
        }
        if(p==nullptr||q==nullptr)
        {
            return false;
        }
        if(p->val!=q->val)
        {
            return false;
        }
        if(isMirrorTree(p->left,q->right)==false)return false;
        if(isMirrorTree(p->right,q->left)==false)return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(root->left==nullptr&&root->right==nullptr)
            return true;
        if(root->left==nullptr||root->right==nullptr)
            return false;
        if(isMirrorTree(root->left,root->right)==false)
            return false;
        return true;

    }
};