# Q94 Binary Tree Inorder Traversal

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
public:
    vector<int> res;
    void inorder_helper(TreeNode *root) {
        if (root == NULL) return;
        inorder_helper(root->left);
        res.push_back(root->val);
        inorder_helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder_helper(root);
        return res;
    }
};
```
