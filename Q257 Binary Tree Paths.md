# Q257 Binary Tree Paths

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
    vector<string> res;
    void helper(TreeNode *root, string curr) {
        if (root == NULL) {
            return;
        }
        if (!root->left && !root->right) {
            curr += to_string(root->val);
            res.push_back(curr);
            return;
        }
        curr += to_string(root->val);
        curr += "->";
        helper(root->left, curr);
        helper(root->right, curr);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        helper(root, str);
        return res;
    }
};
```
