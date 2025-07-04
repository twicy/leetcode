# Q106 Construct Binary Tree from Inorder and Postorder Traversal

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
    unordered_map<int, int> inorder_map;
    TreeNode *helper(vector<int>& inorder, vector<int>& postorder,
        int in_start, int in_end, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[post_end]);
        int left_tree_size = inorder_map[root->val] - in_start;
        root->left = helper(inorder, postorder, in_start, inorder_map[root->val] - 1,
        post_start, post_start + left_tree_size - 1);
        root->right = helper(inorder, postorder, inorder_map[root->val] + 1, in_end,
        post_start + left_tree_size, post_end - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
```
