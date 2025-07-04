# Q617 Merge Two Binary Trees

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        int val = 0;
        if (root1) {
            val += root1->val;
        }
        if (root2) {
            val += root2->val;
        }
        TreeNode *root = new TreeNode(val);
        TreeNode *root1_left = (root1 == NULL) ? (NULL):(root1->left);
        TreeNode *root1_right = (root1 == NULL) ? (NULL):(root1->right);
        TreeNode *root2_left = (root2 == NULL) ? (NULL):(root2->left);
        TreeNode *root2_right = (root2 == NULL) ? (NULL):(root2->right);
        root->left = mergeTrees(root1_left, root2_left);
        root->right = mergeTrees(root1_right, root2_right);
        return root;
    }
};
```
