#include <iostream>
#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long low, long high) {
        if (node == nullptr)
            return true;

        if (node->val <= low || node->val >= high)
            return false;

        return validate(node->left, low, node->val) &&
               validate(node->right, node->val, high);
    }
};

int main() {
    //      2
    //     / \
    //    1   3

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << sol.isValidBST(root); // Output: 1 (true)

    return 0;
}