# Q654 Maximum Binary Tree

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
    int find_max(vector<int> &nums, int left, int right) {
        int maxi = left;
        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[maxi]) {
                maxi = i;
            }
        }
        return maxi;
    }
    TreeNode *helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int maxi = find_max(nums, left, right);
        TreeNode *root = new TreeNode(nums[maxi]);
        root->left = helper(nums, left, maxi - 1);
        root->right = helper(nums, maxi + 1, right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
```
