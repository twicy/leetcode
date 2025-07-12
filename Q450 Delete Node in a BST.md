# Q450 Delete Node in a BST

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            TreeNode *ret;
            if (!root->left && !root->right) {
                ret = NULL;
            } else if (!root->left) {
                ret = root->right;
            } else if (!root->right) {
                ret = root->left;
            } else {
                TreeNode *curr = root->right;
                while (curr->left != NULL) {
                    curr = curr->left;
                }
                curr->left = root->left;
                ret = root->right;
            }
            delete root;
            root = NULL;
            return ret;
        }
        return root;
    }
};
```
