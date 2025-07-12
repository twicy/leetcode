# Q501 Find Mode in Binary Search Tree

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
    TreeNode *prev = NULL;
    int count = 0;
    int maxi = 0;
    vector<int> res;
    void mid_search(TreeNode *curr) {
        if (!curr) {
            return;
        }
        mid_search(curr->left);
        if (prev && prev->val == curr->val) {
            count++;
        } else {
            count = 1;
        }
        prev = curr;
        if (count == maxi) {
            res.push_back(curr->val);
        } else if (count > maxi) {
            maxi = count;
            res.clear();
            res.push_back(curr->val);
        }
        mid_search(curr->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        mid_search(root);
        return res;
    }
};
```
