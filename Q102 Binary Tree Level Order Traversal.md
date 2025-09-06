# Q102 Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL) {
                if (level.size() == 0) break;
                else {
                    res.push_back(level);
                    q.push(NULL);
                    level.clear();
                }
            } else {
                level.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        return res;
    }
};
```
