# Q222 Count Complete Tree Nodes

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
    int countNodes(TreeNode* root) {
        int ret = 0;
        if (root == NULL) {
            return ret;
        }
        if (root->left != NULL) {
            ret += countNodes(root->left);
        }
        if (root->right != NULL) {
            ret += countNodes(root->right);
        }
        return ret + 1;
    }
};
```
