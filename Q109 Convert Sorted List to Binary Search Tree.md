# Q109 Convert Sorted List to Binary Search Tree

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode *find_middle(ListNode *head, ListNode *tail) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next != tail && fast != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode *construct_tree(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return NULL;
        }
        ListNode *mid = find_middle(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = construct_tree(head, mid);
        root->right = construct_tree(mid->next, tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return construct_tree(head, NULL);
    }
};
```
