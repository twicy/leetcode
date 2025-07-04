# Q513 Find Bottom Left Tree Value

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
    int bfs(TreeNode *root) {
        queue<TreeNode *>bank;
        if (root == NULL) {
            return 0;
        }
        bank.push(root);
        bank.push(NULL);
        int next_is_left_most = false;
        int curr_left_most = root->val;
        while (!bank.empty()) {
            TreeNode *front = bank.front();
            bank.pop();
            if (front == NULL) {
                next_is_left_most = true;
                if (!bank.empty()) {
                    bank.push(NULL);
                }
            } else {
                if (next_is_left_most) {
                    curr_left_most = front->val;
                    next_is_left_most = false;
                }
                if (front->left) {
                    bank.push(front->left);
                }   
                if (front->right) {
                    bank.push(front->right);
                }
            }
        }
        return curr_left_most;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
};
```
