# Q103 Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int traversal_dir = 0;
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
                    if (traversal_dir == 1) {
                        reverse(level.begin(), level.end());
                        traversal_dir = 0;
                    } else {
                        traversal_dir = 1;
                    }
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
