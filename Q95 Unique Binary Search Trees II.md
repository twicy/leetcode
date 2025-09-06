# Q95 Unique Binary Search Trees II

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
    vector<TreeNode*> generateTrees_helper(int start, int end) {
        if (start > end) return {NULL};
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_tree = generateTrees_helper(start, i - 1);
            vector<TreeNode*> right_tree = generateTrees_helper(i + 1, end);
            for (TreeNode * left : left_tree) {
                for (TreeNode * right : right_tree) {
                    TreeNode *root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees_helper(1, n);
    }
};
```
