# Q129 Sum Root to Leaf Numbers

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum = 0;
    void helper(TreeNode *root, string str) {
        if (!root) return;
        if (!root->left && !root->right) sum += stoi(str);
        if (root->left) {
            helper(root->left, str + to_string(root->left->val));
        }
        if (root->right) {
            helper(root->right, str + to_string(root->right->val));
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        helper(root, to_string(root->val));
        return sum;
    }
};
```
