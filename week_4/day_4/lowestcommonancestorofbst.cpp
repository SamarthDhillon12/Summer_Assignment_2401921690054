#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return nullptr;
    }
};

int main() {
    /*
             6
           /   \
          2     8
         / \   / \
        0   4 7   9
           / \
          3   5
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->right;       // 8

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    cout << ans->val;  // Output: 6

    return 0;
}